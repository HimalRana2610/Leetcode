#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(int n, vector<vector<int>> &edges, string labels, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        vector dist(n, vector<long long>(k + 1, INT_MAX));
        dist[0][1] = 0;

        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 1);

        while (!pq.empty())
        {
            long long current = get<0>(pq.top());
            int node = get<1>(pq.top()), cnt = get<2>(pq.top());
            pq.pop();

            if (current > dist[node][cnt])
            {
                continue;
            }
            if (node == n - 1)
            {
                return current;
            }

            for (auto &neighbour : adj[node])
            {
                int new_cnt = labels[node] == labels[neighbour.first] ? cnt + 1 : 1;
                if (new_cnt > k)
                {
                    continue;
                }

                long long new_dist = current + neighbour.second;
                if (new_dist < dist[neighbour.first][new_cnt])
                {
                    dist[neighbour.first][new_cnt] = new_dist;
                    pq.emplace(new_dist, neighbour.first, new_cnt);
                }
            }
        }

        return -1;
    }
};