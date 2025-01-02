#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(target > sum || target < -sum || (target + sum) % 2 != 0)
        {
            return 0;
        }

        target = (target + sum) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = target; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};