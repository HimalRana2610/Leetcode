#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfWays(string corridor)
    {
        int n = corridor.length();
        vector<vector<int>> dp(n + 1, vector<int>(3));
        dp[n] = {0, 0, 1};

        for (int i = n - 1; i >= 0; i--)
        {
            if (corridor[i] == 'S')
            {
                dp[i][0] = dp[i + 1][1];
                dp[i][1] = dp[i + 1][2];
                dp[i][2] = dp[i + 1][1];
            }
            else
            {
                dp[i][0] = dp[i + 1][0];
                dp[i][1] = dp[i + 1][1];
                dp[i][2] = (dp[i + 1][0] + dp[i + 1][2]) % 1000000007;
            }
        }

        return dp[0][0];
    }
};