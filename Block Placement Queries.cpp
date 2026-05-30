#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> seg;

public:
    SegmentTree(int n)
    {
        seg.resize(4 * (n + 1), 0);
    }

    void update(int node, int l, int r, int idx, int val)
    {
        if (l == r)
        {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
        {
            update(2 * node, l, mid, idx, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, r, idx, val);
        }

        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
        {
            return 0;
        }

        if (ql <= l && r <= qr)
        {
            return seg[node];
        }

        int mid = (l + r) / 2;
        return max(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
    }
};

class Solution
{
public:
    vector<bool> getResults(vector<vector<int>> &queries)
    {
        int q = queries.size();
        set<int> obstacles;
        obstacles.insert(0);

        for (int i = 0; i < q; i++)
        {
            if (queries[i][0] == 1)
            {
                obstacles.insert(queries[i][1]);
            }
        }

        vector<int> pos(obstacles.begin(), obstacles.end());
        SegmentTree seg(50000);

        for (int i = 1; i < pos.size(); i++)
        {
            seg.update(1, 0, 50000, pos[i], pos[i] - pos[i - 1]);
        }

        vector<bool> ans;
        for (int i = q - 1; i >= 0; i--)
        {
            if (queries[i][0] == 2)
            {
                int p = *prev(obstacles.upper_bound(queries[i][1]));
                ans.push_back(max(seg.query(1, 0, 50000, 0, p), queries[i][1] - p) >= queries[i][2]);
            }
            else
            {
                auto it = obstacles.find(queries[i][1]);
                int left = *prev(it);

                seg.update(1, 0, 50000, queries[i][1], 0);
                auto nxt = next(it);

                if (nxt != obstacles.end())
                {
                    int right = *nxt;
                    seg.update(1, 0, 50000, right, right - left);
                }

                obstacles.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};