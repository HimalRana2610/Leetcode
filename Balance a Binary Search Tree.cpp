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
    void inorder(TreeNode *node, vector<int> &v)
    {
        if (!node)
        {
            return;
        }

        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }

    TreeNode *build(vector<int> &v, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }

        int mid = l + (r - l) / 2;
        TreeNode *node = new TreeNode(v[mid]);

        node->left = build(v, l, mid - 1);
        node->right = build(v, mid + 1, r);

        return node;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> v;
        inorder(root, v);
        return build(v, 0, v.size() - 1);
    }
};