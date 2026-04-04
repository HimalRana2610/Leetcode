#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> rotation(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> tmp(n, vector<int>(m));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }

        return tmp;
    }

    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                total += grid[i][j];
            }
        }

        long long sum, tag;
        unordered_set<long long> exist;

        for (int k = 0; k < 4; k++)
        {
            exist.clear();
            exist.insert(0);
            sum = 0;
            m = grid.size();
            n = grid[0].size();

            if (m < 2)
            {
                grid = rotation(grid);
                continue;
            }
            if (n == 1)
            {
                for (int i = 0; i < m - 1; i++)
                {
                    sum += grid[i][0];
                    tag = sum * 2 - total;

                    if (tag == 0 || tag == grid[0][0] || tag == grid[i][0])
                    {
                        return true;
                    }
                }

                grid = rotation(grid);
                continue;
            }

            for (int i = 0; i < m - 1; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    exist.insert(grid[i][j]);
                    sum += grid[i][j];
                }

                tag = sum * 2 - total;
                if (i == 0)
                {
                    if (tag == 0 || tag == grid[0][0] || tag == grid[0][n - 1])
                    {
                        return true;
                    }

                    continue;
                }

                if (exist.find(tag) != exist.end())
                {
                    return true;
                }
            }

            grid = rotation(grid);
        }

        return false;
    }
};