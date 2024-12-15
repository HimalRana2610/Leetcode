#include<bits/stdc++.h>
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
    pair<int, int> dfs(TreeNode* root)
    {
        if(root == nullptr)
        {
            return {0, 0};
        }

        pair<int, int> leftSub = dfs(root -> left);
        pair<int, int> rightSub = dfs(root -> right);

        int rob = root -> val + leftSub.second + rightSub.second;
        int skip = max(leftSub.first, leftSub.second) + max(rightSub.first, rightSub.second);

        return {rob, skip};
    }

    int rob(TreeNode* root)
    {
        pair<int, int> ans = dfs(root);
        return max(ans.first, ans.second);
    }
};