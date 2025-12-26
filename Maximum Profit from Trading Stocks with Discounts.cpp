#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> combine(bool parentBought, int node, const vector<pair<vector<int>, vector<int>>> &dp, const vector<int> &buy, const vector<int> &sell, int budget)
    {
        vector<int> no(budget + 1, INT_MIN), yes(budget + 1, INT_MIN);
        no[0] = 0;

        int price = parentBought ? (buy[node] / 2) : buy[node];
        int profit = sell[node] - price;

        if (price <= budget)
        {
            yes[price] = profit;
        }

        for (const auto &child : dp)
        {
            vector<int> next_no(budget + 1, INT_MIN);
            for (int i = 0; i <= budget; i++)
            {
                if (no[i] <= INT_MIN / 2)
                {
                    continue;
                }

                for (int j = 0; j + i <= budget; j++)
                {
                    if (child.first[j] <= INT_MIN / 2)
                    {
                        continue;
                    }
                    next_no[i + j] = max(next_no[i + j], no[i] + child.first[j]);
                }
            }

            no.swap(next_no);
            vector<int> next_yes(budget + 1, INT_MIN);

            for (int i = 0; i <= budget; i++)
            {
                if (yes[i] <= INT_MIN / 2)
                {
                    continue;
                }

                for (int j = 0; j + i <= budget; j++)
                {
                    if (child.second[j] <= INT_MIN / 2)
                    {
                        continue;
                    }
                    next_yes[i + j] = max(next_yes[i + j], yes[i] + child.second[j]);
                }
            }

            yes.swap(next_yes);
        }

        vector<int> ans(budget + 1, INT_MIN);
        for (int i = 0; i <= budget; i++)
        {
            ans[i] = max(no[i], yes[i]);
        }

        return ans;
    }

    pair<vector<int>, vector<int>> dfs(int node, const vector<vector<int>> &g, const vector<int> &buy, const vector<int> &sell, int budget)
    {
        vector<pair<vector<int>, vector<int>>> dp;
        for (int child : g[node])
        {
            dp.push_back(dfs(child, g, buy, sell, budget));
        }

        return make_pair(combine(false, node, dp, buy, sell, budget), combine(true, node, dp, buy, sell, budget));
    }

    int maxProfit(int n, vector<int> &present, vector<int> &future, vector<vector<int>> &hierarchy, int budget)
    {
        vector<int> buy(n + 1), sell(n + 1);
        for (int i = 1; i <= n; i++)
        {
            buy[i] = present[i - 1];
            sell[i] = future[i - 1];
        }

        vector<vector<int>> g(n + 1);
        for (int i = 0; i < hierarchy.size(); i++)
        {
            int u = hierarchy[i][0], v = hierarchy[i][1];
            g[u].push_back(v);
        }

        vector<int> root = dfs(1, g, buy, sell, budget).first;
        int ans = 0;

        for (int i = 0; i <= budget; i++)
        {
            ans = max(ans, root[i]);
        }

        return ans;
    }
};