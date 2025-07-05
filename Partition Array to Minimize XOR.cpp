#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minXor(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] ^ nums[i];
        }

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            dp[1][i + 1] = prefix[i + 1];
        }

        for (int i = 2; i <= k; i++)
        {
            for (int j = i; j <= n; j++)
            {
                for (int l = i - 1; l < j; l++)
                {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][l], prefix[j] ^ prefix[l]));
                }
            }
        }

        return dp[k][n];
    }
};