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
    void delete_left(TreeNode *node)
    {
        TreeNode *target = node->left;
        if (!target->left)
        {
            node->left = target->right;
        }
        else if (!target->right)
        {
            node->left = target->left;
        }
        else
        {
            TreeNode *temp = target->left;
            while (temp && temp->right)
            {
                temp = temp->right;
            }

            temp->right = target->right;
            node->left = target->left;
        }
    }

    void delete_right(TreeNode *node)
    {
        TreeNode *target = node->right;
        if (!target->left)
        {
            node->right = target->right;
        }
        else if (!target->right)
        {
            node->right = target->left;
        }
        else
        {
            TreeNode *temp = target->right;
            while (temp && temp->left)
            {
                temp = temp->left;
            }

            temp->left = target->left;
            node->right = target->right;
        }
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
        {
            return root;
        }

        if (root->val == key)
        {
            TreeNode *new_root = new TreeNode(key + 1, root, nullptr);
            deleteNode(new_root, key);
            return new_root->left;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                {
                    if (node->left->val == key)
                    {
                        delete_left(node);
                        return root;
                    }
                    q.push(node->left);
                }
                if (node->right)
                {
                    if (node->right->val == key)
                    {
                        delete_right(node);
                        return root;
                    }
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};