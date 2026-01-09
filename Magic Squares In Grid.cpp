#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i <= n - 3; i++)
        {
            for (int j = 0; j <= m - 3; j++)
            {
                set<int> s;
                for (int x = i; x < i + 3; x++)
                {
                    for (int y = j; y < j + 3; y++)
                    {
                        s.insert(grid[x][y]);
                    }
                }

                if (s.size() != 9 || *s.begin() != 1 || *s.rbegin() != 9)
                {
                    continue;
                }

                int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                bool is_magic = true;

                for (int x = i; x < i + 3; x++)
                {
                    int row_sum = 0;
                    for (int y = j; y < j + 3; y++)
                    {
                        row_sum += grid[x][y];
                    }
                    if (row_sum != sum)
                    {
                        is_magic = false;
                        break;
                    }
                }

                if (!is_magic)
                {
                    continue;
                }

                for (int y = j; y < j + 3; y++)
                {
                    int col_sum = 0;
                    for (int x = i; x < i + 3; x++)
                    {
                        col_sum += grid[x][y];
                    }
                    if (col_sum != sum)
                    {
                        is_magic = false;
                        break;
                    }
                }

                if (!is_magic)
                {
                    continue;
                }

                int d1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2], d2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];
                if (d1 != sum || d2 != sum)
                {
                    continue;
                }

                ans++;
            }
        }

        return ans;
    }
};