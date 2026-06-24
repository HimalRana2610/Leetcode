#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lca(int u, int v, vector<int> &depth, vector<vector<int>> &parent, int log)
    {
        if (depth[u] < depth[v])
        {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];
        for (int bit = 0; bit < log; bit++)
        {
            if ((diff >> bit) & 1)
            {
                u = parent[bit][u];
            }
        }

        if (u == v)
        {
            return u;
        }

        for (int i = log - 1; i >= 0; i--)
        {
            if (parent[i][u] != parent[i][v])
            {
                u = parent[i][u];
                v = parent[i][v];
            }
        }

        return parent[0][u];
    }

    vector<int> assignEdgeWeights(vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        int n = edges.size() + 1, log = 1;
        while ((1 << log) <= n)
        {
            log++;
        }

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> parent(log, vector<int>(n + 1, 0));
        parent[0][1] = 0;

        queue<int> q;
        q.push(1);

        vector<int> depth(n + 1, 0);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbour : adj[node])
            {
                if (neighbour == parent[0][node])
                {
                    continue;
                }

                parent[0][neighbour] = node;
                depth[neighbour] = depth[node] + 1;
                q.push(neighbour);
            }
        }

        for (int i = 1; i < log; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }

        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            pow2[i] = (pow2[i - 1] * 2LL) % 1000000007;
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            int u = queries[i][0], v = queries[i][1];
            int ancestor = lca(u, v, depth, parent, log);
            int pathLength = depth[u] + depth[v] - 2 * depth[ancestor];
            ans.push_back(pathLength == 0 ? 0 : pow2[pathLength - 1]);
        }

        return ans;
    }
};