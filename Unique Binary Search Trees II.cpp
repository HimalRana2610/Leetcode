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
    vector<TreeNode*> generate(int start, int end)
    {
        vector<TreeNode*> ans;
        if(start > end)
        {
            ans.push_back(nullptr);
            return ans;
        }

        for(int i = start; i <= end; i++)
        {
            vector<TreeNode*> leftSub = generate(start, i - 1);
            vector<TreeNode*> rightSub = generate(i + 1, end);

            for(TreeNode* l : leftSub)
            {
                for(TreeNode* r : rightSub)
                {
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n)
    {
        return generate(1, n);
    }
};