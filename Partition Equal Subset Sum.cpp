#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        if(sum % 2 != 0)
        {
            return false;
        }

        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for(int i = 0; i < n; i++)
        {
            for(int j = sum; j >= nums[i]; j--)
            {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[sum];
    }
};