#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumScore(vector<vector<int>> &grid)
    {
        int n = grid[0].size();
        if (n == 1)
        {
            return 0;
        }

        vector<vector<long long>> col(n, vector<long long>(n + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                col[i][j] = col[i][j - 1] + grid[j - 1][i];
            }
        }

        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0)));
        vector<vector<long long>> prev(n + 1, vector<long long>(n + 1, 0)), suffix(n + 1, vector<long long>(n + 1, 0));

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    if (j <= k)
                    {
                        dp[i][j][k] = max(dp[i][j][k], suffix[k][0] + col[i][k] - col[i][j]);
                    }
                    else
                    {
                        dp[i][j][k] = max({dp[i][j][k], suffix[k][j], prev[k][j] + col[i - 1][j] - col[i - 1][k]});
                    }
                }
            }

            for (int j = 0; j <= n; j++)
            {
                prev[j][0] = dp[i][j][0];
                for (int k = 1; k <= n; k++)
                {
                    long long penalty = (k > j) ? (col[i][k] - col[i][j]) : 0;
                    prev[j][k] = max(prev[j][k - 1], dp[i][j][k] - penalty);
                }

                suffix[j][n] = dp[i][j][n];
                for (int k = n - 1; k >= 0; k--)
                {
                    suffix[j][k] = max(suffix[j][k + 1], dp[i][j][k]);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i <= n; i++)
        {
            ans = max({ans, dp[n - 1][n][i], dp[n - 1][0][i]});
        }

        return ans;
    }
};