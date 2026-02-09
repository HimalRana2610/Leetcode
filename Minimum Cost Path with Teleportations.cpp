#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> cells;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cells.push_back({i, j});
            }
        }

        sort(cells.begin(), cells.end(), [&](const pair<int, int> &a, const pair<int, int> &b)
             { return grid[a.first][a.second] < grid[b.first][b.second]; });

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        k++;

        while (k--)
        {
            int cost = INT_MAX;
            for (int i = 0, j = 0; i < cells.size(); i++)
            {
                cost = min(cost, dp[cells[i].first][cells[i].second]);
                if (i + 1 < cells.size() && grid[cells[i].first][cells[i].second] == grid[cells[i + 1].first][cells[i + 1].second])
                {
                    continue;
                }
                for (int r = j; r <= i; r++)
                {
                    dp[cells[r].first][cells[r].second] = cost;
                }
                j = i + 1;
            }

            for (int i = m - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    if (i == m - 1 && j == n - 1)
                    {
                        dp[i][j] = 0;
                        continue;
                    }
                    if (i != m - 1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + grid[i + 1][j]);
                    }
                    if (j != n - 1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }
        }

        return dp[0][0];
    }
};