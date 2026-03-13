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
    void dfs(TreeNode *node, string current, vector<string> &nums)
    {
        if (node->val == 0)
        {
            current.push_back('0');
        }
        else
        {
            current.push_back('1');
        }

        if (!node->left && !node->right)
        {
            nums.push_back(current);
            return;
        }

        if (node->left)
        {
            dfs(node->left, current, nums);
        }
        if (node->right)
        {
            dfs(node->right, current, nums);
        }
    }

    int sumRootToLeaf(TreeNode *root)
    {
        vector<string> nums;
        dfs(root, "", nums);

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int n = nums[i].length();
            for (int j = 0; j < n; j++)
            {
                if (nums[i][j] == '1')
                {
                    ans += (1 << (n - j - 1));
                }
            }
        }

        return ans;
    }
};