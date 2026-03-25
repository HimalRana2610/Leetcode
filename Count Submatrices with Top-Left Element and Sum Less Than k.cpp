#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> prefix(n, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefix[i][j + 1] = prefix[i][j] + grid[i][j];
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefix[i][j + 1] += prefix[i - 1][j + 1];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (prefix[i][j + 1] <= k)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};