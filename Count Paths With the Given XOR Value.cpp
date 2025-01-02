#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(16, 0)));
        dp[0][0][grid[0][0]] = 1;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int x = 0; x < 16; x++)
                {
                    if(dp[i][j][x] > 0)
                    {
                        if(j < n - 1)
                        {
                            int xor_val = x ^ grid[i][j + 1];
                            dp[i][j + 1][xor_val] = (dp[i][j + 1][xor_val] + dp[i][j][x]) % 1000000007;
                        }
                        if(i < m - 1)
                        {
                            int xor_val = x ^ grid[i + 1][j];
                            dp[i + 1][j][xor_val] = (dp[i + 1][j][xor_val] + dp[i][j][x]) % 1000000007;
                        }
                    }
                }
            }
        }

        return dp[m - 1][n - 1][k];
    }
};