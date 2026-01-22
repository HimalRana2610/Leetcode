#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
private:
    int n;
    vector<int> cnt, covered, xs;

    void modify(int ql, int qr, int qval, int left, int right, int pos)
    {
        if (xs[right + 1] <= ql || xs[left] >= qr)
        {
            return;
        }

        if (ql <= xs[left] && xs[right + 1] <= qr)
        {
            cnt[pos] += qval;
        }
        else
        {
            int mid = (left + right) / 2;
            modify(ql, qr, qval, left, mid, pos * 2 + 1);
            modify(ql, qr, qval, mid + 1, right, pos * 2 + 2);
        }

        if (cnt[pos] > 0)
        {
            covered[pos] = xs[right + 1] - xs[left];
        }
        else
        {
            if (left == right)
            {
                covered[pos] = 0;
            }
            else
            {
                covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
            }
        }
    }

public:
    SegmentTree(vector<int> &xs_) : xs(xs_)
    {
        n = xs.size() - 1;
        cnt.resize(4 * n, 0);
        covered.resize(4 * n, 0);
    }

    void update(int ql, int qr, int qval)
    {
        modify(ql, qr, qval, 0, n - 1, 0);
    }

    int query()
    {
        return covered[0];
    }
};

class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        vector<tuple<int, int, int, int>> events;
        set<int> s;

        for (int i = 0; i < squares.size(); i++)
        {
            int x = squares[i][0], y = squares[i][1], l = squares[i][2];
            events.emplace_back(y, 1, x, x + l);
            events.emplace_back(y + l, -1, x, x + l);
            s.insert(x);
            s.insert(x + l);
        }

        sort(events.begin(), events.end());
        vector<int> xs(s.begin(), s.end());

        SegmentTree segTree(xs);
        vector<double> prefix;
        vector<int> widths;

        double area = 0.0;
        int prev = get<0>(events[0]);

        for (int i = 0; i < events.size(); i++)
        {
            int y = get<0>(events[i]), d = get<1>(events[i]), xl = get<2>(events[i]), xr = get<3>(events[i]);
            int l = segTree.query();

            area += 1LL * l * (y - prev);
            segTree.update(xl, xr, d);
            prefix.push_back(area);
            widths.push_back(segTree.query());
            prev = y;
        }

        int pos = lower_bound(prefix.begin(), prefix.end(), (long long)(area + 1) / 2) - prefix.begin() - 1;
        return get<0>(events[pos]) + (area - 2 * prefix[pos]) / (2.0 * widths[pos]);
    }
};