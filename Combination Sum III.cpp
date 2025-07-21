#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int last, int k, int n, vector<int> current, int sum, vector<vector<int>> &ans)
    {
        if (sum > n)
        {
            return;
        }

        if (current.size() == k)
        {
            if (sum == n)
            {
                ans.push_back(current);
            }
            return;
        }

        for (int i = last + 1; i <= 9; i++)
        {
            current.push_back(i);
            dfs(i, k, n, current, sum + i, ans);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= 9; i++)
        {
            dfs(i, k, n, {i}, i, ans);
        }

        return ans;
    }
};