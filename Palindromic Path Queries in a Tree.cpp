#include <bits/stdc++.h>
using namespace std;

class BIT
{
    int n;
    vector<int> tree;

public:
    BIT(int _n) : n(_n), tree(_n + 1) {}

    static int lowbit(int x)
    {
        return x & -x;
    }

    void update(int x, int v)
    {
        while (x <= n)
        {
            tree[x] ^= v;
            x += lowbit(x);
        }
    }

    int query(int x)
    {
        int ret = 0;
        while (x)
        {
            ret ^= tree[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void updateRange(int l, int r, int v)
    {
        update(l, v);
        update(r + 1, v);
    }
};

class Solution
{
public:
    void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &dep, vector<vector<int>> &fa, int &timer, vector<int> &l, vector<int> &r)
    {
        l[node] = ++timer;
        fa[node][0] = parent;

        for (int neighbour : adj[node])
        {
            if (neighbour == parent)
            {
                continue;
            }
            dep[neighbour] = dep[node] + 1;
            dfs(neighbour, node, adj, dep, fa, timer, l, r);
        }

        r[node] = timer;
    }

    int lca(int u, int v, vector<int> &dep, vector<vector<int>> &fa, int log)
    {
        if (dep[u] < dep[v])
        {
            swap(u, v);
        }

        int diff = dep[u] - dep[v];
        for (int i = 0; i < log; ++i)
        {
            if ((diff >> i) & 1)
            {
                u = fa[u][i];
            }
        }

        if (u == v)
        {
            return u;
        }

        for (int i = log - 1; i >= 0; --i)
        {
            if (fa[u][i] != fa[v][i])
            {
                u = fa[u][i];
                v = fa[v][i];
            }
        }

        return fa[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>> &edges, string s, vector<string> &queries)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int log = 32 - __builtin_clz(n), timer = 0;
        vector<vector<int>> fa(n, vector<int>(log));
        vector<int> dep(n), l(n), r(n);

        dfs(0, 0, adj, dep, fa, timer, l, r);

        for (int j = 1; j < log; j++)
        {
            for (int i = 0; i < n; i++)
            {
                fa[i][j] = fa[fa[i][j - 1]][j - 1];
            }
        }

        BIT bit(n + 1);
        for (int i = 0; i < n; ++i)
        {
            bit.updateRange(l[i], r[i], 1 << (s[i] - 'a'));
        }

        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            stringstream ss(queries[i]);
            string op;
            ss >> op;

            if (op == "update")
            {
                int u;
                char c;
                ss >> u >> c;

                bit.updateRange(l[u], r[u], (1 << (s[u] - 'a')) ^ (1 << (c - 'a')));
                s[u] = c;
            }
            else
            {
                int u, v;
                ss >> u >> v;

                int w = lca(u, v, dep, fa, log);
                int mask = bit.query(l[u]) ^ bit.query(l[v]) ^ (1 << (s[w] - 'a'));
                ans.push_back(__builtin_popcount(mask) <= 1);
            }
        }

        return ans;
    }
};