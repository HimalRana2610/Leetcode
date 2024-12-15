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
    int maxPathSum(TreeNode* root)
    {
        int m = INT_MIN;

        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int
        {
            if(!node)
            {
                return 0;
            }

            int leftMax = max(dfs(node -> left), 0);
            int rightMax = max(dfs(node -> right), 0);

            m = max(m, node -> val + leftMax + rightMax);
            return node -> val + max(leftMax, rightMax);
        };

        dfs(root);
        return m;
    }
};