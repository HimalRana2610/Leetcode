#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, int parent, vector<vector<pair<int, int>>> &adj, int &ans)
    {
        for (auto &neighbour : adj[node])
        {
            if (neighbour.first != parent)
            {
                ans += neighbour.second;
                dfs(neighbour.first, node, adj, ans);
            }
        }
    }

    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back({connections[i][1], 1});
            adj[connections[i][1]].push_back({connections[i][0], 0});
        }

        int ans = 0;
        dfs(0, -1, adj, ans);

        return ans;
    }
};