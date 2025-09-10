#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), fr = -1;
        for (int i = 0; i < n && fr == -1; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    fr = i;
                    break;
                }
            }
        }

        int lr = -1;
        for (int i = n - 1; i >= 0 && lr == -1; i--)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    lr = i;
                    break;
                }
            }
        }

        int fc = -1;
        for (int j = 0; j < m && fc == -1; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (grid[i][j] == 1)
                {
                    fc = j;
                    break;
                }
            }
        }

        int lc = -1;
        for (int j = m - 1; j >= 0 && lc == -1; j--)
        {
            for (int i = 0; i < n; i++)
            {
                if (grid[i][j] == 1)
                {
                    lc = j;
                    break;
                }
            }
        }

        return (lr - fr + 1) * (lc - fc + 1);
    }
};