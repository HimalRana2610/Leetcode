#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> diag1(n + m - 1, vector<int>(m + 1, 0)), diag2(n + m - 1, vector<int>(m + 1, 0));

        for (int r = 0; r < m; r++)
        {
            for (int d = 0; d < n + m - 1; d++)
            {
                diag1[d][r + 1] = diag1[d][r];
                diag2[d][r + 1] = diag2[d][r];
            }
            for (int c = 0; c < n; c++)
            {
                diag1[r - c + (n - 1)][r + 1] += grid[r][c];
                diag2[r + c][r + 1] += grid[r][c];
            }
        }

        set<int, greater<int>> ans;
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                ans.insert(grid[r][c]);
                if (ans.size() > 3)
                {
                    ans.erase(prev(ans.end()));
                }

                int mk = min({r, c, m - 1 - r, n - 1 - c});
                for (int k = 1; k <= mk; k++)
                {
                    int d1 = r + c - k, d2 = r + c + k, d3 = r - c + (n - 1) - k, d4 = r - c + (n - 1) + k;
                    int sum = (diag2[d1][r + 1] - diag2[d1][r - k]) + (diag2[d2][r + k + 1] - diag2[d2][r]) + (diag1[d3][r + 1] - diag1[d3][r - k]) + (diag1[d4][r + k + 1] - diag1[d4][r]) - grid[r - k][c] - grid[r][c + k] - grid[r][c - k] - grid[r + k][c];

                    ans.insert(sum);
                    if (ans.size() > 3)
                    {
                        ans.erase(prev(ans.end()));
                    }
                }
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};