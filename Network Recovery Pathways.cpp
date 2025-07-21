#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k)
    {
        int n = online.size(), m = edges.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> cost;

        for (int i = 0; i < m; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            cost.push_back(edges[i][2]);
        }

        sort(cost.begin(), cost.end());
        cost.erase(unique(cost.begin(), cost.end()), cost.end());

        int low = 0, high = cost.size() - 1, ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            vector<long long> dist(n, LLONG_MAX);
            dist[0] = 0;

            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            pq.push({0, 0});

            while (!pq.empty())
            {
                long long current = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                if (current > dist[node] || current > k)
                {
                    continue;
                }
                if (node == n - 1)
                {
                    break;
                }

                for (auto &neighbour : adj[node])
                {
                    if (!online[neighbour.first] || neighbour.second < cost[mid])
                    {
                        continue;
                    }

                    long long next = current + neighbour.second;
                    if (next < dist[neighbour.first])
                    {
                        dist[neighbour.first] = next;
                        pq.push({next, neighbour.first});
                    }
                }
            }

            if (dist[n - 1] <= k)
            {
                ans = cost[mid];
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};