#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(nums);

        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i <= n - l; i++)
            {
                dp[i] = (dp[i] + dp[i + 1]) % 10;
            }
        }

        return dp[0];
    }
};