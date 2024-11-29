#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int deleteAndEarn(vector<int>& nums)
    {
        int m = *max_element(nums.begin(), nums.end());
        vector<int> points(m + 1, 0), dp(m + 1, 0);

        for(int i = 0; i < nums.size(); i++)
        {
            points[nums[i]] += nums[i];
        }

        dp[0] = points[0];
        dp[1] = points[1];

        for(int i = 2; i <= m; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + points[i]);
        }

        return dp[m];
    }
};