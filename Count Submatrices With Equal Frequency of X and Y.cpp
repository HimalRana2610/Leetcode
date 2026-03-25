#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> x(n, vector<int>(m + 1, 0)), y(n, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                x[i][j + 1] = x[i][j] + (grid[i][j] == 'X');
                y[i][j + 1] = y[i][j] + (grid[i][j] == 'Y');
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                x[i][j + 1] += x[i - 1][j + 1];
                y[i][j + 1] += y[i - 1][j + 1];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (x[i][j + 1] >= 1 && x[i][j + 1] == y[i][j + 1])
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};