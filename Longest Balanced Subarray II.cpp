#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    int n;
    vector<int> sum, mn, mx, lazy;
    vector<bool> has_lazy;

public:
    SegmentTree(int x)
    {
        n = x;
        sum.assign(4 * n + 5, 0);
        mn.assign(4 * n + 5, 0);
        mx.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);
        has_lazy.assign(4 * n + 5, 0);
    }

    void pull(int v)
    {
        sum[v] = sum[v << 1] + sum[v << 1 | 1];
        mn[v] = min(mn[v << 1], sum[v << 1] + mn[v << 1 | 1]);
        mx[v] = max(mx[v << 1], sum[v << 1] + mx[v << 1 | 1]);
    }

    void applySet(int v, int l, int r, int val)
    {
        int len = r - l + 1;
        sum[v] = 1LL * val * len;

        if (val == 0)
        {
            mn[v] = 0;
            mx[v] = 0;
        }
        else if (val > 0)
        {
            mn[v] = val;
            mx[v] = 1LL * val * len;
        }
        else
        {
            mn[v] = 1LL * val * len;
            mx[v] = val;
        }

        has_lazy[v] = true;
        lazy[v] = val;
    }

    void push(int v, int l, int r)
    {
        if (!has_lazy[v] || l == r)
        {
            return;
        }

        int m = (l + r) >> 1;
        applySet(v << 1, l, m, lazy[v]);
        applySet(v << 1 | 1, m + 1, r, lazy[v]);
        has_lazy[v] = false;
    }

    void update(int pos, int newval)
    {
        update(1, 0, n - 1, pos, pos, newval);
    }

    void update(int v, int l, int r, int ql, int qr, int val)
    {
        if (ql <= l && r <= qr)
        {
            applySet(v, l, r, val);
            return;
        }

        push(v, l, r);
        int m = (l + r) >> 1;

        if (ql <= m)
        {
            update(v << 1, l, m, ql, qr, val);
        }

        if (qr > m)
        {
            update(v << 1 | 1, m + 1, r, ql, qr, val);
        }

        pull(v);
    }

    int query(int x)
    {
        if (x == 0)
        {
            return -1;
        }

        if (x < mn[1] || x > mx[1])
        {
            return n;
        }

        int pref = 0;
        return query(1, 0, n - 1, x, pref);
    }

    int query(int v, int l, int r, int x, int &pref)
    {
        if (l == r)
        {
            if (pref + sum[v] == x)
            {
                return l;
            }

            return n;
        }

        push(v, l, r);

        int m = (l + r) >> 1, L = v << 1, R = v << 1 | 1, leftMin = pref + mn[L], leftMax = pref + mx[L];
        if (x >= leftMin && x <= leftMax)
        {
            return query(L, l, m, x, pref);
        }
        else
        {
            pref += sum[L];
            return query(R, m + 1, r, x, pref);
        }
    }
};

class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int n = nums.size(), sum = 0, ans = 0;
        vector<int> last(*max_element(nums.begin(), nums.end()) + 1, -1);
        SegmentTree s(n);

        for (int i = 0; i < n; i++)
        {
            if (last[nums[i]] != -1)
            {
                s.update(last[nums[i]], 0);
            }
            else
            {
                if (nums[i] % 2 == 0)
                {
                    sum--;
                }
                else
                {
                    sum++;
                }
            }

            last[nums[i]] = i;
            if (nums[i] % 2 == 0)
            {
                s.update(i, -1);
            }
            else
            {
                s.update(i, 1);
            }

            ans = max(ans, i - s.query(sum));
        }

        return ans;
    }
};