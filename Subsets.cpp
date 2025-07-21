#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &nums, int index, vector<int> current, vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        solve(nums, index + 1, current, ans);

        current.pop_back();
        solve(nums, index + 1, current, ans);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        solve(nums, 0, {}, ans);

        return ans;
    }
};