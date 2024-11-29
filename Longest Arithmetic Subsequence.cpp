#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int longestArithSeqLength(vector<int>& nums)
    {
        int n = nums.size();
        if(n < 2)
        {
            return n;
        }

        vector<map<int, int>> dp(n);
        int ans = 2;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                int d = nums[i] - nums[j];
                if(dp[j].count(d))
                {
                    dp[i][d] = dp[j][d] + 1;
                }
                else
                {
                    dp[i][d] = 2;
                }
                ans = max(ans, dp[i][d]);
            }
        }
        return ans;
    }
};