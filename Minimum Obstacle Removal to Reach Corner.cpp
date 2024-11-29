#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minimumObstacles(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, numeric_limits<int>::max()));
        ans[0][0] = grid[0][0];

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty())
        {
            auto c = pq.top();
            pq.pop();

            int r = c[0], x = c[1], y = c[2];
            if(x == m - 1 && y == n - 1)
            {
                return r;
            }

            vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for(int i = 0 ; i < dirs.size(); i++)
            {
                int nx = x + dirs[i].first, ny = y + dirs[i].second;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n)
                {
                    int nr = r + grid[nx][ny];
                    if(nr < ans[nx][ny])
                    {
                        ans[nx][ny] = nr;
                        pq.push({nr, nx, ny});
                    }
                }
            }
        }

        return ans[m - 1][n - 1];
    }
};