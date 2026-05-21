#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        int nl = min(m / 2, n / 2);

        for (int l = 0; l < nl; l++)
        {
            vector<int> r, c, val;
            for (int i = l; i < m - l - 1; ++i)
            {
                r.push_back(i);
                c.push_back(l);
                val.push_back(grid[i][l]);
            }
            for (int j = l; j < n - l - 1; ++j)
            {
                r.push_back(m - l - 1);
                c.push_back(j);
                val.push_back(grid[m - l - 1][j]);
            }
            for (int i = m - l - 1; i > l; --i)
            {
                r.push_back(i);
                c.push_back(n - l - 1);
                val.push_back(grid[i][n - l - 1]);
            }
            for (int j = n - l - 1; j > l; --j)
            {
                r.push_back(l);
                c.push_back(j);
                val.push_back(grid[l][j]);
            }

            int total = val.size();
            for (int i = 0; i < total; ++i)
            {
                int idx = (i + total - (k % total)) % total;
                grid[r[i]][c[i]] = val[idx];
            }
        }

        return grid;
    }
};