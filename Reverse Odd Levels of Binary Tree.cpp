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
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);

        bool odd = false;
        while(!q.empty())
        {
            int level = q.size();
            vector<TreeNode*> nodes;

            for(int i = 0; i < level; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                nodes.push_back(node);
                if(node -> left)
                {
                    q.push(node -> left);
                }
                if(node -> right)
                {
                    q.push(node -> right);
                }
            }

            if(odd)
            {
                for(int i = 0; i < nodes.size() / 2; i++)
                {
                    swap(nodes[i] -> val, nodes[nodes.size() - i - 1] -> val);
                }
            }
            odd = !odd;
        }

        return root;
    }
};