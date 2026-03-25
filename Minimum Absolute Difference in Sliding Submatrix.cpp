#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));

        for (int i = 0; i <= n - k; i++)
        {
            for (int j = 0; j <= m - k; j++)
            {
                vector<int> temp;
                for (int x = i; x < i + k; x++)
                {
                    for (int y = j; y < j + k; y++)
                    {
                        temp.push_back(grid[x][y]);
                    }
                }

                int mn = INT_MAX;
                sort(temp.begin(), temp.end());

                for (int t = 1; t < temp.size(); t++)
                {
                    if (temp[t] == temp[t - 1])
                    {
                        continue;
                    }

                    mn = min(mn, temp[t] - temp[t - 1]);
                }

                if (mn != INT_MAX)
                {
                    ans[i][j] = mn;
                }
            }
        }

        return ans;
    }
};