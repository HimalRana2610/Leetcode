#include<bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank, weights;
    public:
    DSU(int n)
    {
        parent = vector<int>(n);
        rank = vector<int>(n, 0);
        weights = vector<int>(n, 131071);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if(x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union_find(int x, int y, int weight)
    {
        int xx = find(x), yy = find(y);
        if(rank[xx] < rank[yy])
        {
            parent[xx] = yy;
        }
        else
        {
            parent[yy] = xx;
        }

        weights[xx] = weights[yy] = weights[xx] & weights[yy] & weight;
        if(rank[xx] == rank[yy])
        {
            rank[xx]++;
        }
    }

    int minimumCostOfWalk(int x, int y)
    {
        if(x == y)
        {
            return 0;
        }
        if(find(x) != find(y))
        {
            return -1;
        }

        return weights[find(x)];
    }
};

class Solution
{
    public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query)
    {
        DSU uf(n);
        for(int i = 0; i < edges.size(); i++)
        {
            uf.union_find(edges[i][0], edges[i][1], edges[i][2]);
        }

        vector<int> ans;
        for(int i = 0; i < query.size(); i++)
        {
            ans.push_back(uf.minimumCostOfWalk(query[i][0], query[i][1]));
        }

        return ans;
    }
};