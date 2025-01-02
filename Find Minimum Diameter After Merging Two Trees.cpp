#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void bfs(vector<vector<int>>& tree, int node, int distance, int &farthest, vector<int> &dist)
    {
        dist[node] = distance;
        if(distance > dist[farthest])
        {
            farthest = node;
        }

        for(auto i : tree[node])
        {
            if(dist[i] == -1)
            {
                bfs(tree, i, distance + 1, farthest, dist);
            }
        }
    }

    int diameter(vector<vector<int>> &tree, int start, int &farthest)
    {
        int n = tree.size();
        farthest = start;

        vector<int> dist(n, -1);
        bfs(tree, start, 0, farthest, dist);

        return dist[farthest];
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2)
    {
        int n = edges1.size(), m = edges2.size();
        vector<vector<int>> tree1(n + 1), tree2(m + 1);

        for(int i = 0; i < n; i++)
        {
            tree1[edges1[i][0]].push_back(edges1[i][1]);
            tree1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for(int i = 0; i < m; i++)
        {
            tree2[edges2[i][0]].push_back(edges2[i][1]);
            tree2[edges2[i][1]].push_back(edges2[i][0]);
        }

        int f1 = 0, f2 = 0;
        diameter(tree1, 0, f1);
        diameter(tree2, 0, f2);

        int d1 = diameter(tree1, f1, f1), d2 = diameter(tree2, f2, f2);
        return max((d1 + 1) / 2 + (d2 + 1) / 2 + 1, max(d1, d2));
    }
};