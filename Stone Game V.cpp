#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stoneGameV(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i <= n - l; i++)
            {
                int j = i + l - 1;
                for (int k = i; k < j; k++)
                {
                    int left = prefix[k + 1] - prefix[i], right = prefix[j + 1] - prefix[k + 1];
                    if (left > right)
                    {
                        dp[i][j] = max(dp[i][j], right + dp[k + 1][j]);
                    }
                    else if (left < right)
                    {
                        dp[i][j] = max(dp[i][j], left + dp[i][k]);
                    }
                    else
                    {
                        dp[i][j] = max(dp[i][j], left + max(dp[i][k], dp[k + 1][j]));
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};