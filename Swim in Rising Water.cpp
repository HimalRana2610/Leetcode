#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty())
        {
            int current = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();

            if (x == n - 1 && y == n - 1)
            {
                return current;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i].first, ny = y + dirs[i].second;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    int newTime = max(current, grid[nx][ny]);
                    if (newTime < dist[nx][ny])
                    {
                        dist[nx][ny] = newTime;
                        pq.push({newTime, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};