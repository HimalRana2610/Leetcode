#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minCost(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});

        while(!pq.empty())
        {
            int current = get<0>(pq.top()), x = get<1>(pq.top()), y = get<2>(pq.top());
            pq.pop();

            if(x == m - 1 && y == n - 1)
            {
                return current;
            }

            int dir = grid[x][y] - 1;
            int dx = dirs[dir].first, dy = dirs[dir].second;
            int nx = x + dx, ny = y + dy;

            if(nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if(current < cost[nx][ny])
                {
                    cost[nx][ny] = current;
                    pq.push({current, nx, ny});
                }
            }

            for(int i = 0; i < 4; i++)
            {
                dx = dirs[i].first;
                dy = dirs[i].second;
                nx = x + dx;
                ny = y + dy;

                if(nx >= 0 && nx < m && ny >= 0 && ny < n)
                {
                    int nc = current + 1;
                    if(nc < cost[nx][ny])
                    {
                        cost[nx][ny] = nc;
                        pq.push({nc, nx, ny});
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};