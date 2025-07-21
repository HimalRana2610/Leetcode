#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &candidates, int target, int index, vector<int> &current, int sum, vector<vector<int>> &ans)
    {
        if (sum == target)
        {
            ans.push_back(current);
            return;
        }

        if (sum > target || index >= candidates.size())
        {
            return;
        }

        current.push_back(candidates[index]);
        solve(candidates, target, index, current, sum + candidates[index], ans);

        current.pop_back();
        solve(candidates, target, index + 1, current, sum, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> current;

        solve(candidates, target, 0, current, 0, ans);
        return ans;
    }
};