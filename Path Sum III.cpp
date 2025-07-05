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
    void dfs(TreeNode *node, long long current, int target, unordered_map<long long, int> &prefix, int &ans)
    {
        current += node->val;
        ans += prefix[current - target];
        prefix[current]++;

        if (node->left)
        {
            dfs(node->left, current, target, prefix, ans);
        }
        if (node->right)
        {
            dfs(node->right, current, target, prefix, ans);
        }

        prefix[current]--;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return 0;
        }

        unordered_map<long long, int> prefix;
        prefix[0] = 1;

        int ans = 0;
        dfs(root, 0, targetSum, prefix, ans);

        return ans;
    }
};