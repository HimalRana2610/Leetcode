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
    long long calculate_sum(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }

        return node->val + calculate_sum(node->left) + calculate_sum(node->right);
    }

    long long dfs(TreeNode *node, long long sum, long long &m)
    {
        if (!node)
        {
            return 0;
        }

        long long sub_sum = node->val + dfs(node->left, sum, m) + dfs(node->right, sum, m);
        long long product = sub_sum * (sum - sub_sum);

        m = max(m, product);
        return sub_sum;
    }

    int maxProduct(TreeNode *root)
    {
        long long sum = calculate_sum(root), ans = 0;
        dfs(root, sum, ans);

        return ans % 1000000007;
    }
};