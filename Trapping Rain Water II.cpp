#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int trapRainWater(vector<vector<int>>& heightMap)
    {
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
                {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int ans = 0;

        while(!pq.empty())
        {
            int height = get<0>(pq.top()), x = get<1>(pq.top()), y = get<2>(pq.top());
            pq.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i].first, ny = y + dirs[i].second;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny])
                {
                    if(heightMap[nx][ny] < height)
                    {
                        ans += height - heightMap[nx][ny];
                    }

                    pq.push({max(heightMap[nx][ny], height), nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        return ans;
    }
};