#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestMagicSquare(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), ans = 1;
        for (int i = 2; i <= min(n, m); i++)
        {
            for (int j = 0; j <= n - i; j++)
            {
                for (int k = 0; k <= m - i; k++)
                {
                    bool flag = true;
                    int target = 0;

                    for (int l = 0; l < i; l++)
                    {
                        target += grid[j][k + l];
                    }

                    for (int l = 0; l < i; l++)
                    {
                        int row = 0;
                        for (int o = 0; o < i; o++)
                        {
                            row += grid[j + l][k + o];
                        }

                        if (row != target)
                        {
                            flag = false;
                            break;
                        }
                    }

                    if (!flag)
                    {
                        continue;
                    }

                    for (int l = 0; l < i; l++)
                    {
                        int col = 0;
                        for (int o = 0; o < i; o++)
                        {
                            col += grid[j + o][k + l];
                        }

                        if (col != target)
                        {
                            flag = false;
                            break;
                        }
                    }

                    if (!flag)
                    {
                        continue;
                    }

                    int diag1 = 0, diag2 = 0;
                    for (int l = 0; l < i; l++)
                    {
                        diag1 += grid[j + l][k + l];
                        diag2 += grid[j + l][k + i - 1 - l];
                    }

                    if (diag1 != target || diag2 != target)
                    {
                        flag = false;
                    }

                    if (flag)
                    {
                        ans = i;
                    }
                }
            }
        }

        return ans;
    }
};