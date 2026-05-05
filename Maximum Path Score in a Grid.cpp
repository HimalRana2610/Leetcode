#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPathScore(vector<vector<int>> &grid, int K)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(K + 1, -1)));
        dp[0][0][0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k <= K; k++)
                {
                    if (dp[i][j][k] == -1)
                    {
                        continue;
                    }
                    if (i + 1 < n)
                    {
                        int cost = (grid[i + 1][j] == 0 ? 0 : 1);
                        if (k + cost <= K)
                        {
                            dp[i + 1][j][k + cost] = max(dp[i + 1][j][k + cost], dp[i][j][k] + grid[i + 1][j]);
                        }
                    }
                    if (j + 1 < m)
                    {
                        int cost = (grid[i][j + 1] == 0 ? 0 : 1);
                        if (k + cost <= K)
                        {
                            dp[i][j + 1][k + cost] = max(dp[i][j + 1][k + cost], dp[i][j][k] + grid[i][j + 1]);
                        }
                    }
                }
            }
        }

        int ans = -1;
        for (int i = 0; i <= K; i++)
        {
            ans = max(ans, dp[n - 1][m - 1][i]);
        }

        return ans;
    }
};