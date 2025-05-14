#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minTimeToReach(vector<vector<int>>& moveTime)
    {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!pq.empty())
        {
            int time = get<0>(pq.top()), x = get<1>(pq.top()), y = get<2>(pq.top());
            pq.pop();

            if(time > dist[x][y])
            {
                continue;
            }

            if(x == n - 1 && y == m - 1)
            {
                return time;
            }

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    int newTime = max(time, moveTime[nx][ny]) + 1;
                    if(newTime < dist[nx][ny])
                    {
                        dist[nx][ny] = newTime;
                        pq.push({newTime, nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};