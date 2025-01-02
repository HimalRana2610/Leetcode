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
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> ans;
        if(!root)
        {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size(), m = INT_MIN;
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                m = max(m, node -> val);

                if(node -> left)
                {
                    q.push(node -> left);
                }
                if(node -> right)
                {
                    q.push(node -> right);
                }
            }
            ans.push_back(m);
        }

        return ans;
    }
};