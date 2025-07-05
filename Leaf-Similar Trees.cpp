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
    void dfs(TreeNode *node, vector<int> &arr)
    {
        if (!node->left && !node->right)
        {
            arr.push_back(node->val);
            ;
        }

        if (node->left)
        {
            dfs(node->left, arr);
        }
        if (node->right)
        {
            dfs(node->right, arr);
        }
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> arr1, arr2;
        dfs(root1, arr1);
        dfs(root2, arr2);

        if (arr1.size() != arr2.size())
        {
            return false;
        }

        for (int i = 0; i < arr1.size(); i++)
        {
            if (arr1[i] != arr2[i])
            {
                return false;
            }
        }

        return true;
    }
};