#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        if (grid[0][0] || grid.back().back())
        {
            return 0;
        }

        int n = grid.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (q.size())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();

            int v = grid[x][y];
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i].first, ny = y + dirs[i].second;
                if (min(nx, ny) >= 0 && max(nx, ny) < n && !grid[nx][ny])
                {
                    grid[nx][ny] = v + 1;
                    q.push({nx, ny});
                }
            }
        }

        priority_queue<tuple<int, int, int>> pq;
        pq.push({grid[0][0], 0, 0});

        while (pq.size())
        {
            int safe = get<0>(pq.top()), x = get<1>(pq.top()), y = get<2>(pq.top());
            pq.pop();

            if (x == n - 1 && y == n - 1)
            {
                return safe - 1;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i].first, ny = y + dirs[i].second;
                if (min(nx, ny) >= 0 && max(nx, ny) < n && grid[nx][ny] > 0)
                {
                    pq.push({min(safe, grid[nx][ny]), nx, ny});
                    grid[nx][ny] *= -1;
                }
            }
        }

        return grid.back().back() - 1;
    }
};