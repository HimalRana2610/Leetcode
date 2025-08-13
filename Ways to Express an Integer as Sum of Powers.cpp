#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfWays(int n, int x)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            long long power = pow(i, x);
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= power)
                {
                    dp[i][j] = ((long long)dp[i][j] + dp[i - 1][j - power]) % 1000000007;
                }
            }
        }

        return dp[n][n];
    }
};