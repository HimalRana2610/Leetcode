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
    int i = 0;
    public:
    TreeNode* recoverFromPreorder(string traversal, int depth = 0)
    {
        if(i >= traversal.size())
        {
            return NULL;
        }

        int d = 0;
        while(traversal[i] == '-')
        {
            d++;
            i++;
        }

        if(d < depth)
        {
            i -= d;
            return NULL;
        }

        int x = 0;
        while(isdigit(traversal[i]))
        {
            x = x * 10 + (traversal[i] - '0');
            i++;
        }

        TreeNode* root = new TreeNode(x, recoverFromPreorder(traversal, d + 1), recoverFromPreorder(traversal, d + 1));
        return root;
    }
};