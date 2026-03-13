#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent;

    DSU(const vector<int> &p) : parent(p) {}

    int find(int x)
    {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    void join(int x, int y)
    {
        int px = find(x), py = find(y);
        if (px != py)
        {
            parent[px] = py;
        }
    }
};

class Solution
{
public:
    int maxStability(int n, vector<vector<int>> &edges, int k)
    {
        if (edges.size() < n - 1)
        {
            return -1;
        }

        vector<vector<int>> sorted(edges.begin(), edges.end());
        vector<vector<int>> must, optional;

        for (int i = 0; i < sorted.size(); i++)
        {
            if (sorted[i][3] == 1)
            {
                must.push_back(sorted[i]);
            }
            else
            {
                optional.push_back(sorted[i]);
            }
        }

        if (must.size() > n - 1)
        {
            return -1;
        }

        sort(optional.begin(), optional.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] > b[2]; });

        int selected = 0, m = 2e5;
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        DSU dsu_init(parent);

        for (int i = 0; i < must.size(); i++)
        {
            if (dsu_init.find(must[i][0]) == dsu_init.find(must[i][1]) || selected == n - 1)
            {
                return -1;
            }

            dsu_init.join(must[i][0], must[i][1]);
            selected++;
            m = min(m, must[i][2]);
        }

        int l = 0, r = m, ans = -1;
        while (l < r)
        {
            int mid = l + ((r - l + 1) >> 1), s = selected, doubled = 0;
            DSU dsu(dsu_init.parent);

            for (int i = 0; i < optional.size(); i++)
            {
                if (dsu.find(optional[i][0]) == dsu.find(optional[i][1]))
                {
                    continue;
                }

                if (optional[i][2] >= mid)
                {
                    dsu.join(optional[i][0], optional[i][1]);
                    s++;
                }
                else if (doubled < k && optional[i][2] * 2 >= mid)
                {
                    doubled++;
                    dsu.join(optional[i][0], optional[i][1]);
                    s++;
                }
                else
                {
                    break;
                }

                if (s == n - 1)
                {
                    break;
                }
            }

            if (s != n - 1)
            {
                r = mid - 1;
            }
            else
            {
                ans = mid;
                l = mid;
            }
        }

        return ans;
    }
};