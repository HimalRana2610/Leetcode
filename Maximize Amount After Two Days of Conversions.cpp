#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    unordered_map<string, unordered_map<string, double>> build_graph(vector<vector<string>>& pairs, vector<double>& rates)
    {
        unordered_map<string, unordered_map<string, double>> graph;
        for(int i = 0; i < pairs.size(); i++)
        {
            string from = pairs[i][0], to = pairs[i][1];
            double rate = rates[i];
            graph[from][to] = rate;
            graph[to][from] = 1.0 / rate;
        }
        return graph;
    }

    unordered_map<string, double> amount(unordered_map<string, unordered_map<string, double>>& graph, string initialCurrency)
    {
        unordered_map<string, double> maxAmounts;
        for(auto& entry : graph)
        {
            maxAmounts[entry.first] = 0.0;
        }
        maxAmounts[initialCurrency] = 1.0;

        for(int i = 0; i < graph.size(); i++)
        {
            bool updated = false;
            for(auto& from : graph)
            {
                for(auto& to : from.second)
                {
                    double newAmount = maxAmounts[from.first] * to.second;
                    if(newAmount > maxAmounts[to.first])
                    {
                        maxAmounts[to.first] = newAmount;
                        updated = true;
                    }
                }
            }
            if(!updated)
            {
                break;
            }
        }
        return maxAmounts;
    }

    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2)
    {
        unordered_map<string, unordered_map<string, double>> graph1 = build_graph(pairs1, rates1);
        unordered_map<string, unordered_map<string, double>> graph2 = build_graph(pairs2, rates2);

        unordered_map<string, double> day1 = amount(graph1, initialCurrency);

        double ans = 0.0;
        for(auto &currency : day1)
        {
            string c = currency.first;
            double a = currency.second;

            unordered_map<string, double> day2 = amount(graph2, c);
            ans = max(ans, a * day2[initialCurrency]);
        }

        return ans;
    }
};