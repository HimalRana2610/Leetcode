#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> dijkstra(int start, const vector<vector<pair<int, int>>> &adj)
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, start});

        vector<long long> costs(26, -1);
        while (!pq.empty())
        {
            long long cost = pq.top().first;
            int current = pq.top().second;
            pq.pop();

            if (costs[current] != -1 && costs[current] < cost)
            {
                continue;
            }

            for (auto &node : adj[current])
            {
                int target = node.first, conversion = node.second;
                long long new_cost = cost + conversion;

                if (costs[target] == -1 || new_cost < costs[target])
                {
                    costs[target] = new_cost;
                    pq.push({new_cost, target});
                }
            }
        }

        return costs;
    }

    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        vector<vector<pair<int, int>>> adj(26);
        for (int i = 0; i < original.size(); i++)
        {
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }

        vector<vector<long long>> costs(26, vector<long long>(26));
        for (int i = 0; i < 26; i++)
        {
            costs[i] = dijkstra(i, adj);
        }

        long long ans = 0;
        int len = source.length();

        for (int i = 0; i < len; i++)
        {
            if (source[i] != target[i])
            {
                if (costs[source[i] - 'a'][target[i] - 'a'] == -1)
                {
                    return -1;
                }
                ans += costs[source[i] - 'a'][target[i] - 'a'];
            }
        }

        return ans;
    }
};