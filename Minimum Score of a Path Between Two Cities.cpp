#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0], v = roads[i][1], w = roads[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> visited(n + 1, false);
        visited[1] = true;

        queue<int> q;
        q.push(1);

        int ans = INT_MAX;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &neighbour : adj[node])
            {
                ans = min(ans, neighbour.second);
                if (!visited[neighbour.first])
                {
                    visited[neighbour.first] = true;
                    q.push(neighbour.first);
                }
            }
        }

        return ans;
    }
};