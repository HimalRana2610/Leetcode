#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    vector<int> parent, rank;

public:
    UnionFind(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int pu = find(u), pv = find(v);
        if (pu == pv)
        {
            return;
        }
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution
{
public:
    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
    {
        UnionFind uf(c);
        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0], v = connections[i][1];
            uf.unionByRank(u, v);
        }

        vector<bool> is_online(c + 1, true);
        vector<int> offline(c + 1, 0);

        for (int i = 0; i < queries.size(); i++)
        {
            int choice = queries[i][0], u = queries[i][1];
            if (choice == 2)
            {
                is_online[u] = false;
                offline[u]++;
            }
        }

        unordered_map<int, int> cnt;
        for (int i = 1; i <= c; i++)
        {
            int root = uf.find(i);
            if (!cnt.count(root))
            {
                cnt[root] = -1;
            }

            if (is_online[i])
            {
                if (cnt[root] == -1 || cnt[root] > i)
                {
                    cnt[root] = i;
                }
            }
        }

        vector<int> ans;
        for (int i = queries.size() - 1; i >= 0; i--)
        {
            int choice = queries[i][0], u = queries[i][1];
            int root = uf.find(u);
            int station = cnt[root];

            if (choice == 1)
            {
                if (is_online[u])
                {
                    ans.push_back(u);
                }
                else
                {
                    ans.push_back(station);
                }
            }

            if (choice == 2)
            {
                if (offline[u] > 1)
                {
                    offline[u]--;
                }
                else
                {
                    is_online[u] = true;
                    if (station == -1 || station > u)
                    {
                        cnt[root] = u;
                    }
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};