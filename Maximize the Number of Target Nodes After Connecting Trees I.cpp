#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(vector<vector<int>> &tree, int node, int parent, int k)
    {
        if (k < 0)
        {
            return 0;
        }

        int ans = 1;
        for (auto neighbour : tree[node])
        {
            if (neighbour != parent)
            {
                ans += dfs(tree, neighbour, node, k - 1);
            }
        }

        return ans;
    }

    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        int n = edges1.size(), m = edges2.size();
        vector<vector<int>> tree1(n + 1), tree2(m + 1);

        for (int i = 0; i < n; i++)
        {
            int u = edges1[i][0], v = edges1[i][1];
            tree1[u].push_back(v);
            tree1[v].push_back(u);
        }

        for (int i = 0; i < m; i++)
        {
            int u = edges2[i][0], v = edges2[i][1];
            tree2[u].push_back(v);
            tree2[v].push_back(u);
        }

        vector<int> cnt1(n + 1);
        for (int i = 0; i <= n; i++)
        {
            cnt1[i] = dfs(tree1, i, -1, k);
        }

        vector<int> cnt2(m + 1);
        for (int i = 0; i <= m; i++)
        {
            cnt2[i] = dfs(tree2, i, -1, k - 1);
        }

        int target2 = *max_element(cnt2.begin(), cnt2.end());
        vector<int> ans(n + 1);

        for (int i = 0; i <= n; i++)
        {
            ans[i] = cnt1[i] + target2;
        }

        return ans;
    }
};