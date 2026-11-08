#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePaths(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(2, 0)));
        dp[0][0][0] = 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (i > 0)
                {
                    if (grid[i - 1][j] == 0)
                    {
                        dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % 1000000007;
                    }
                    else
                    {
                        dp[i][j][0] = dp[i - 1][j][1];
                    }
                }

                if (j > 0)
                {
                    if (grid[i][j - 1] == 0)
                    {
                        dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % 1000000007;
                    }
                    else
                    {
                        dp[i][j][1] = dp[i][j - 1][0];
                    }
                }
            }
        }

        return (dp[n - 1][m - 1][0] + dp[n - 1][m - 1][1]) % 1000000007;
    }
};