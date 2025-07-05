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
    void dfs(TreeNode *node, bool dir, int current, int &ans)
    {
        ans = max(ans, current);
        if (node->left)
        {
            dfs(node->left, true, dir ? 1 : current + 1, ans);
        }
        if (node->right)
        {
            dfs(node->right, false, dir ? current + 1 : 1, ans);
        }
    }

    int longestZigZag(TreeNode *root)
    {
        int ans = 0;
        dfs(root, true, 0, ans);

        return ans;
    }
};