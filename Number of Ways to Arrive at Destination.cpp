#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<vector<pair<int, int>>> graph(n);
        for(int i = 0; i < roads.size(); i++)
        {
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        vector<int> paths(n, 0);
        paths[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        while(!pq.empty())
        {
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > dist[node])
            {
                continue;
            }

            for(auto &neighbour : graph[node])
            {
                if(dist[node] + neighbour.second < dist[neighbour.first])
                {
                    dist[neighbour.first] = dist[node] + neighbour.second;
                    paths[neighbour.first] = paths[node];
                    pq.push({dist[neighbour.first], neighbour.first});
                }
                else if(dist[node] + neighbour.second == dist[neighbour.first])
                {
                    paths[neighbour.first] = (paths[neighbour.first] + paths[node]) % 1000000007;
                }
            }
        }

        return paths[n - 1];
    }
};