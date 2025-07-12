#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true;
        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[node][i] == 1 && !visited[i])
            {
                dfs(i, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size(), ans = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans++;
                dfs(i, isConnected, visited);
            }
        }

        return ans;
    }
};