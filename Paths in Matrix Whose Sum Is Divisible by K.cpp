#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int r = 0; r < k; r++)
                {
                    if (i > 0)
                    {
                        int nr = (r + grid[i][j]) % k;
                        dp[i][j][nr] = (dp[i][j][nr] + dp[i - 1][j][r]) % 1000000007;
                    }
                    if (j > 0)
                    {
                        int nr = (r + grid[i][j]) % k;
                        dp[i][j][nr] = (dp[i][j][nr] + dp[i][j - 1][r]) % 1000000007;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};