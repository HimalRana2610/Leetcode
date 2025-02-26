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
    unordered_map<int, int> post_index;
    int pre_index = 0;

    public:
    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int post_start, int post_end)
    {
        if(post_start > post_end)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pre_index++]);

        if(post_start == post_end)
        {
            return root;
        }

        int left_val = preorder[pre_index];
        int left_end = post_index[left_val];

        root -> left = build(preorder, postorder, post_start, left_end);
        root -> right = build(preorder, postorder, left_end + 1, post_end - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder)
    {
        for(int i = 0; i < postorder.size(); i++)
        {
            post_index[postorder[i]] = i;
        }

        return build(preorder, postorder, 0, preorder.size() - 1);
    }
};