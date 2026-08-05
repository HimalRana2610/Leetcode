#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, unordered_set<int> &suspicious)
    {
        suspicious.insert(node);
        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                dfs(neighbour, adj, visited, suspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        vector<vector<int>> adj(n), incoming(n);
        for (int i = 0; i < invocations.size(); i++)
        {
            int u = invocations[i][0], v = invocations[i][1];
            adj[u].push_back(v);
            incoming[v].push_back(u);
        }

        unordered_set<int> suspicious;
        vector<bool> visited(n, false);
        visited[k] = true;

        dfs(k, adj, visited, suspicious);

        bool flag = true;
        for (int node : suspicious)
        {
            if (!flag)
            {
                break;
            }

            for (int neighbour : incoming[node])
            {
                if (suspicious.find(neighbour) == suspicious.end())
                {
                    flag = false;
                    break;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (flag && suspicious.find(i) != suspicious.end())
            {
                continue;
            }
            ans.push_back(i);
        }

        return ans;
    }
};