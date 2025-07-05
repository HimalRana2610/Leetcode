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
    int maxLevelSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        int ans = 1, m = INT_MIN;
        for (int level = 1; !q.empty(); level++)
        {
            int n = q.size(), sum = 0;
            while (n--)
            {
                TreeNode *current = q.front();
                q.pop();

                sum += current->val;
                if (current->left)
                {
                    q.push(current->left);
                }
                if (current->right)
                {
                    q.push(current->right);
                }
            }

            if (sum > m)
            {
                ans = level;
                m = sum;
            }
        }

        return ans;
    }
};