#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int assignEdgeWeights(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<vector<int>> adj(n + 2);

        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n + 2, false);
        visited[1] = true;

        queue<int> q;
        q.push(1);

        int depth = -1;
        while (!q.empty())
        {
            int s = q.size();
            depth++;

            while (s--)
            {
                int node = q.front();
                q.pop();

                for (int &neighbour : adj[node])
                {
                    if (!visited[neighbour])
                    {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
        }

        int j = 2, ans = 1;
        for (int i = depth - 1; i; i >>= 1)
        {
            if (i & 1)
            {
                ans = 1ll * ans * j % 1000000007;
            }
            j = 1ll * j * j % 1000000007;
        }

        return ans;
    }
};