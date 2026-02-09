#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(int n, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], 2 * edges[i][2]});
        }

        vector<bool> visited(n, false);
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();

            if (node == n - 1)
            {
                return dist[node];
            }

            if (visited[node])
            {
                continue;
            }

            visited[node] = true;
            for (auto &neighbour : adj[node])
            {
                if (dist[node] + neighbour.second < dist[neighbour.first])
                {
                    dist[neighbour.first] = dist[node] + neighbour.second;
                    pq.push({dist[neighbour.first], neighbour.first});
                }
            }
        }

        return -1;
    }
};