#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    pair<int, int> dfs(TreeNode *node, int &ans)
    {
        if (!node)
        {
            return {0, 0};
        }

        pair<int, int> l = dfs(node->left, ans), r = dfs(node->right, ans);
        if (node->val == (node->val + l.first + r.first) / (1 + l.second + r.second))
        {
            ans++;
        }

        return {node->val + l.first + r.first, 1 + l.second + r.second};
    }

    int averageOfSubtree(TreeNode *root)
    {
        int ans = 0;
        dfs(root, ans);

        return ans;
    }
};