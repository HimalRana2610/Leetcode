#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long dfs(vector<int> &nums, vector<vector<long long>> &dp)
    {
        int n = nums.size();
        if (n < 3)
        {
            return 1;
        }

        vector<int> left, right;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] < nums[0])
            {
                left.push_back(nums[i]);
            }
            else
            {
                right.push_back(nums[i]);
            }
        }

        return ((((dfs(left, dp) % 1000000007) * (dfs(right, dp) % 1000000007)) % 1000000007) * dp[n - 1][left.size()]) % 1000000007;
    }

    int numOfWays(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1);

        for (int i = 0; i < n + 1; ++i)
        {
            dp[i] = vector<long long>(i + 1, 1);
            for (int j = 1; j < i; ++j)
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;
            }
        }

        return (dfs(nums, dp) - 1) % 1000000007;
    }
};