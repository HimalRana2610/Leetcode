#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(unordered_map<string, vector<pair<string, double>>> &adj, string node, string target, unordered_set<string> &visited, double current, double &ans)
    {
        if (node == target)
        {
            ans = current;
        }
        if (ans != -1.0)
        {
            return;
        }

        visited.insert(node);
        for (auto &neighbour : adj[node])
        {
            if (visited.find(neighbour.first) == visited.end())
            {
                dfs(adj, neighbour.first, target, visited, current * neighbour.second, ans);
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < equations.size(); i++)
        {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }

        vector<double> ans(queries.size(), -1.0);
        for (int i = 0; i < queries.size(); i++)
        {
            unordered_set<string> visited;
            if (adj.count(queries[i][0]) && adj.count(queries[i][1]))
            {
                dfs(adj, queries[i][0], queries[i][1], visited, 1.0, ans[i]);
            }
        }

        return ans;
    }
};