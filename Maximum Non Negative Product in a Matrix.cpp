#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProductPath(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> mx(m, vector<long long>(n)), mn(m, vector<long long>(n));
        mx[0][0] = mn[0][0] = grid[0][0];

        for (int i = 1; i < m; i++)
        {
            mx[i][0] = mx[i - 1][0] * grid[i][0];
            mn[i][0] = mn[i - 1][0] * grid[i][0];
        }

        for (int j = 1; j < n; j++)
        {
            mx[0][j] = mx[0][j - 1] * grid[0][j];
            mn[0][j] = mn[0][j - 1] * grid[0][j];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                long long current = grid[i][j];
                if (current >= 0)
                {
                    mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]) * current;
                    mn[i][j] = min(mn[i - 1][j], mn[i][j - 1]) * current;
                }
                else
                {
                    mx[i][j] = min(mn[i - 1][j], mn[i][j - 1]) * current;
                    mn[i][j] = max(mx[i - 1][j], mx[i][j - 1]) * current;
                }
            }
        }

        return max(-1LL, mx[m - 1][n - 1]) % 1000000007;
    }
};