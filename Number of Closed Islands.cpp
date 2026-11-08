#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, bool &closed)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            closed = false;
            return;
        }

        if (grid[i][j] == 1)
        {
            return;
        }

        grid[i][j] = 1;
        dfs(grid, i + 1, j, closed);
        dfs(grid, i - 1, j, closed);
        dfs(grid, i, j + 1, closed);
        dfs(grid, i, j - 1, closed);
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    bool closed = true;
                    dfs(grid, i, j, closed);

                    if (closed)
                    {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};