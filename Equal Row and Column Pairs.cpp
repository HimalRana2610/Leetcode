#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<string> rows(n), cols(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rows[i] += to_string(grid[i][j]) + '.';
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cols[i] += to_string(grid[j][i]) + '.';
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rows[i] == cols[j])
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};