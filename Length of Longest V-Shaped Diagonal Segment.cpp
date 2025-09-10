#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(vector<vector<int>> &grid, vector<pair<int, int>> &dirs, vector<vector<vector<vector<int>>>> &dp, int x, int y, int z, bool turn, int target)
    {
        int nx = x + dirs[z].first, ny = y + dirs[z].second;
        if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] != target)
        {
            return 0;
        }
        if (dp[nx][ny][z][turn] != -1)
        {
            return dp[nx][ny][z][turn];
        }

        int ans = dfs(grid, dirs, dp, nx, ny, z, turn, 2 - target);
        if (turn)
        {
            ans = fmax(ans, dfs(grid, dirs, dp, nx, ny, (z + 1) % 4, false, 2 - target));
        }

        dp[nx][ny][z][turn] = ans + 1;
        return ans + 1;
    }

    int lenOfVDiagonal(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        vector<vector<vector<vector<int>>>> dp(m, vector<vector<vector<int>>>(n, vector<vector<int>>(4, vector<int>(2, -1))));

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        ans = fmax(ans, dfs(grid, dirs, dp, i, j, k, true, 2) + 1);
                    }
                }
            }
        }

        return ans;
    }
};