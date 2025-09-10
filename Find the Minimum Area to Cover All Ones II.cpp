#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minsum(vector<vector<int>> &grid, int u, int d, int l, int r)
    {
        int mii = grid.size(), mai = 0, mij = grid[0].size(), maj = 0;
        for (int i = u; i <= d; i++)
        {
            for (int j = l; j <= r; j++)
            {
                if (grid[i][j] == 1)
                {
                    mii = min(mii, i);
                    mai = max(mai, i);
                    mij = min(mij, j);
                    maj = max(maj, j);
                }
            }
        }

        return (mii <= mai) ? (mai - mii + 1) * (maj - mij + 1) : INT_MAX / 3;
    }

    int solve(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int ans = n * m;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                ans = min({ans, minsum(grid, 0, i, 0, m - 1) + minsum(grid, i + 1, n - 1, 0, j) + minsum(grid, i + 1, n - 1, j + 1, m - 1), minsum(grid, 0, i, 0, j) + minsum(grid, 0, i, j + 1, m - 1) + minsum(grid, i + 1, n - 1, 0, m - 1)});
            }
        }

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                ans = min(ans, minsum(grid, 0, i, 0, m - 1) + minsum(grid, i + 1, j, 0, m - 1) + minsum(grid, j + 1, n - 1, 0, m - 1));
            }
        }

        return ans;
    }

    int minimumSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> rotated(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                rotated[m - j - 1][i] = grid[i][j];
            }
        }

        return min(solve(grid), solve(rotated));
    }
};