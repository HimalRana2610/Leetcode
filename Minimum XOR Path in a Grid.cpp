#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<bool> next(1024, false);
        vector<vector<bool>> dp(m, vector<bool>(1024, false));
        dp[0][grid[0][0]] = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }

                fill(next.begin(), next.end(), false);

                for (int k = 0; k < 1024; k++)
                {
                    if (dp[j][k] || (j > 0 && dp[j - 1][k]))
                    {
                        next[k ^ grid[i][j]] = true;
                    }
                }

                dp[j] = next;
            }
        }

        for (int i = 0; i < 1024; i++)
        {
            if (dp[m - 1][i])
            {
                return i;
            }
        }

        return -1;
    }
};