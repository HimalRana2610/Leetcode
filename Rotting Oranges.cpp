#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), total = 0, rotten = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    total++;
                }
                else if (grid[i][j] == 2)
                {
                    total++;
                    rotten++;
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        if (rotten == total)
        {
            return 0;
        }

        int ans = -1;
        while (!q.empty())
        {
            int l = q.size();
            while (l--)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dirs[i].first, ny = y + dirs[i].second;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == 1)
                    {
                        rotten++;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            ans++;
        }

        if (rotten != total)
        {
            return -1;
        }

        return ans;
    }
};