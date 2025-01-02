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
    int min_swap(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> index;

        for(int i = 0; i < n; i++)
        {
            index.push_back({arr[i], i});
        }

        sort(index.begin(), index.end());

        vector<bool> visited(n, false);
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(visited[i] || index[i].second == i)
            {
                continue;
            }

            int cycle = 0;
            for(int j = i; !visited[j]; j = index[j].second)
            {
                visited[j] = true;
                cycle++;
            }

            if(cycle > 1)
            {
                ans += cycle - 1;
            }
        }

        return ans;
    }

    int minimumOperations(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> levels;
        while(!q.empty())
        {
            int s = q.size();
            vector<int> level;

            for(int i = 0; i < s; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if(node -> left)
                {
                    q.push(node -> left);
                }
                if(node -> right)
                {
                    q.push(node -> right);
                }
            }
            levels.push_back(level);
        }

        int ans = 0;
        for(int i = 0; i < levels.size(); i++)
        {
            ans += min_swap(levels[i]);
        }

        return ans;
    }
};