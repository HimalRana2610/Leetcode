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
    void dfs(TreeNode *node, int m, int &ans)
    {
        if (node->val >= m)
        {
            ans++;
            m = node->val;
        }

        if (node->left)
        {
            dfs(node->left, m, ans);
        }
        if (node->right)
        {
            dfs(node->right, m, ans);
        }
    }

    int goodNodes(TreeNode *root)
    {
        int ans = 0;
        dfs(root, INT_MIN, ans);

        return ans;
    }
};