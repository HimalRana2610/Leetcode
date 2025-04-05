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
    pair<TreeNode*, int> dfs(TreeNode* node)
    {
        if(!node)
        {
            return {node, 0};
        }

        pair<TreeNode*, int> left_node = dfs(node -> left), right_node = dfs(node -> right);
        if(left_node.second > right_node.second)
        {
            return {left_node.first, left_node.second + 1};
        }
        else if(left_node.second < right_node.second)
        {
            return {right_node.first, right_node.second + 1};
        }

        return {node, left_node.second + 1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root)
    {
        return dfs(root).first;
    }
};