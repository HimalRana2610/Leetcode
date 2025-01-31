#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
    {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isWater[i][j] == 1)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i].first, ny = y + dirs[i].second;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && ans[nx][ny] == -1)
                {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return ans;
    }
};