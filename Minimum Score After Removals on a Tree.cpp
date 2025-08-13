#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, int parent, vector<int> &nums, vector<vector<int>> &adj, vector<int> &prefix, vector<unordered_set<int>> &children)
    {
        prefix[node] = nums[node];
        children[node].insert(node);

        for (auto &neighbour : adj[node])
        {
            if (neighbour != parent)
            {
                dfs(neighbour, node, nums, adj, prefix, children);
                prefix[node] ^= prefix[neighbour];
                children[node].insert(children[neighbour].begin(), children[neighbour].end());
            }
        }
    }

    int minimumScore(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> prefix(n, 0);
        vector<unordered_set<int>> children(n);

        dfs(0, -1, nums, adj, prefix, children);

        int total = prefix[0], ans = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int t1, t2, t3;
                if (children[i].count(j))
                {
                    t1 = prefix[j];
                    t2 = prefix[i] ^ prefix[j];
                    t3 = total ^ prefix[i];
                }
                else if (children[j].count(i))
                {
                    t1 = prefix[i];
                    t2 = prefix[i] ^ prefix[j];
                    t3 = total ^ prefix[j];
                }
                else
                {
                    t1 = prefix[i];
                    t2 = prefix[j];
                    t3 = total ^ prefix[i] ^ prefix[j];
                }

                ans = min(ans, max({t1, t2, t3}) - min({t1, t2, t3}));
            }
        }

        return ans;
    }
};