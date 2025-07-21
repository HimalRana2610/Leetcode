#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] %= k;
            for (int j = 0; j < k; j++)
            {
                dp[j][nums[i]] = dp[nums[i]][j] + 1;
                ans = max(ans, dp[j][nums[i]]);
            }
        }

        return ans;
    }
};