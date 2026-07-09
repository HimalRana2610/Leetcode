#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.emplace(grid[0][0], 0, 0);

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!pq.empty())
        {
            int val = get<0>(pq.top()), x = get<1>(pq.top()), y = get<2>(pq.top());
            pq.pop();

            if (dist[x][y] >= 0)
            {
                continue;
            }

            dist[x][y] = val;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i].first, ny = y + dirs[i].second;
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || dist[nx][ny] >= 0)
                {
                    continue;
                }
                pq.emplace(val + grid[nx][ny], nx, ny);
            }
        }

        return dist[m - 1][n - 1] < health;
    }
};