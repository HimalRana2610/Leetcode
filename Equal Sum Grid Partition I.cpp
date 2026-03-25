#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        long long total = 0;
        vector<long long> rows(n);

        for (int i = 0; i < n; i++)
        {
            long long sum = 0;
            for (int j = 0; j < m; j++)
            {
                sum += grid[i][j];
                total += grid[i][j];
            }

            rows[i] = sum;
        }

        if (total % 2 != 0)
        {
            return false;
        }

        long long current = 0;
        for (int i = 0; i < n; i++)
        {
            current += rows[i];
            if (current == total / 2)
            {
                return true;
            }
        }

        vector<long long> cols(m);
        for (int j = 0; j < m; j++)
        {
            long long sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += grid[i][j];
            }

            cols[j] = sum;
        }

        current = 0;
        for (int j = 0; j < m; j++)
        {
            current += cols[j];
            if (current == total / 2)
            {
                return true;
            }
        }

        return false;
    }
};