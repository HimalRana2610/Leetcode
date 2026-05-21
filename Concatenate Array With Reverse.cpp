#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> concatWithReverse(vector<int> &nums)
    {
        vector<int> ans(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ans.push_back(nums[i]);
        }

        return ans;
    }
};