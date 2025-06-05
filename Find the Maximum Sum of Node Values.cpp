#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        dp[n][0] = INT_MIN;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2; j++)
            {
                dp[i][j] = max(dp[i + 1][j ^ 1] + (nums[i] ^ k), dp[i + 1][j] + nums[i]);
            }
        }

        return dp[0][1];
    }
};