#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxMoves(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<pair<int, int>> dir = {{-1, 1}, {0, 1}, {1, 1}};

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == n - 1)
                {
                    dp[j][i] = 0;
                }
                else
                {
                    for(int k = 0; k < dir.size(); k++)
                    {
                        int nr = j + dir[k].first;
                        int nc = i + dir[k].second;

                        if((nr >= 0) && (nr < m) && (nc < n) && (grid[nr][nc]) > (grid[j][i]))
                        {
                            dp[j][i] = max(dp[j][i], dp[nr][nc] + 1);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            ans = max(ans, dp[i][0]);
        }

        return ans;
    }
};