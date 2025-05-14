#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minTimeToReach(vector<vector<int>>& moveTime)
    {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        dist[0][0][0] = 0;

        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
        pq.push({0, 0, 0, 0});

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!pq.empty())
        {
            int time = get<0>(pq.top()), x = get<1>(pq.top()), y = get<2>(pq.top()), p = get<3>(pq.top());
            pq.pop();

            if(time > dist[x][y][p])
            {
                continue;
            }

            if(x == n - 1 && y == m - 1)
            {
                return time;
            }

            int cost = (p == 0 ? 1 : 2), np = 1 - p;
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    int newTime = max(time, moveTime[nx][ny]) + cost;
                    if(newTime < dist[nx][ny][np])
                    {
                        dist[nx][ny][np] = newTime;
                        pq.push({newTime, nx, ny, np});
                    }
                }
            }
        }

        return -1;
    }
};