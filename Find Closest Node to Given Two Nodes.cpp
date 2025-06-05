#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, int depth, vector<int> &edges, vector<int> &dist)
    {
        if (dist[node] != -1)
        {
            return;
        }

        dist[node] = depth;
        if (edges[node] != -1)
        {
            dfs(edges[node], depth + 1, edges, dist);
        }
    }

    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);

        dfs(node1, 0, edges, dist1);
        dfs(node2, 0, edges, dist2);

        int ans = INT_MAX, dist = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (dist1[i] != -1 && dist2[i] != -1)
            {
                if (max(dist1[i], dist2[i]) < dist)
                {
                    ans = i;
                    dist = max(dist1[i], dist2[i]);
                }
                else if (max(dist1[i], dist2[i]) == dist)
                {
                    ans = min(ans, i);
                }
            }
        }

        if (ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};