#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minimumTime(vector<vector<int>>& grid)
    {
        if(grid[0][1] > 1 && grid[1][0] > 1)
        {
            return -1;
        }

        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        while(!pq.empty())
        {
            int t = pq.top()[0], r = pq.top()[1], c = pq.top()[2];
            pq.pop();

            if(r == m - 1 && c == n - 1)
            {
                return t;
            }

            if(visited[r][c])
            {
                continue;
            }
            visited[r][c] = true;

            for(int i = 0; i < dirs.size(); i++)
            {
                int nr = r + dirs[i].first, nc = c + dirs[i].second;
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc])
                {
                    pq.push({max(grid[nr][nc] + ((grid[nr][nc] - t) % 2 == 0), t + 1), nr, nc});
                }
            }
        }

        return -1;
    }
};