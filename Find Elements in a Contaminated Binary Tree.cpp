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

class FindElements
{
    TreeNode* root;

    void adjust(TreeNode* node, int x)
    {
        if(!node)
        {
            return;
        }
        node -> val = x;
        adjust(node -> left, 2 * x + 1);
        adjust(node -> right, 2 * x + 2);
    }

    bool dfs(TreeNode* node, int target)
    {
        if(!node)
        {
            return false;
        }
        if(node -> val == target)
        {
            return true;
        }
        return dfs(node -> left, target) || dfs(node -> right, target);
    }

    public:
    FindElements(TreeNode* root)
    {
        adjust(root, 0);
        this -> root = root;
    }

    bool find(int target)
    {
        return dfs(root, target);
    }
};