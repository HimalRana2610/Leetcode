#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int node, vector<int> &component)
    {
        visited[node] = true;
        component.push_back(node);

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(adj, visited, neighbor, component);
            }
        }
    }

    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        int n = source.size();
        vector<vector<int>> adj(n);

        for (auto &swap : allowedSwaps)
        {
            adj[swap[0]].push_back(swap[1]);
            adj[swap[1]].push_back(swap[0]);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                vector<int> component;
                dfs(adj, visited, i, component);

                unordered_map<int, int> source_cnt;
                unordered_map<int, int> target_cnt;

                for (int index : component)
                {
                    source_cnt[source[index]]++;
                    target_cnt[target[index]]++;
                }

                for (const auto &cnt : source_cnt)
                {
                    int value = cnt.first, count = cnt.second;
                    ans += max(0, count - target_cnt[value]);
                }
            }
        }

        return ans;
    }
};