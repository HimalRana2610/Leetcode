#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int node, string &colors, vector<vector<int>> &adj, vector<vector<int>> &cnt, vector<int> &visited)
    {
        if (!visited[node])
        {
            visited[node] = 1;
            for (int neighbour : adj[node])
            {
                if (dfs(neighbour, colors, adj, cnt, visited) == INT_MAX)
                {
                    return INT_MAX;
                }

                for (int i = 0; i < 26; i++)
                {
                    cnt[node][i] = max(cnt[node][i], cnt[neighbour][i]);
                }
            }

            cnt[node][colors[node] - 'a']++;
            visited[node] = 2;
        }

        if (visited[node] == 2)
        {
            return cnt[node][colors[node] - 'a'];
        }

        return INT_MAX;
    }

    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        vector<vector<int>> cnt(n, vector<int>(26));
        vector<int> visited(n);

        int ans = 0;
        for (int i = 0; i < n && ans != INT_MAX; i++)
        {
            ans = max(ans, dfs(i, colors, adj, cnt, visited));
        }

        if (ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};