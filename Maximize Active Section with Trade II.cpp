#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
private:
    int n;
    vector<int> arr, seg;

    void build(int p, int l, int r)
    {
        if (l == r)
        {
            seg[p] = arr[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
    }

    int _query(int p, int l, int r, int L, int R)
    {
        if (L <= l && r <= R)
        {
            return seg[p];
        }

        int mid = (l + r) >> 1, ans = 0;
        if (L <= mid)
        {
            ans = max(ans, _query(p << 1, l, mid, L, R));
        }
        if (R > mid)
        {
            ans = max(ans, _query(p << 1 | 1, mid + 1, r, L, R));
        }

        return ans;
    }

public:
    SegmentTree(const vector<int> &arr) : arr(arr)
    {
        n = arr.size();
        seg.resize(n << 2, 0);
        build(1, 0, n - 1);
    }

    int query(int L, int R)
    {
        if (L > R)
        {
            return 0;
        }

        return _query(1, 0, n - 1, L, R);
    }
};

class Solution
{
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>> &queries)
    {
        int n = s.length(), ones = count(s.begin(), s.end(), '1');
        vector<int> zeros, left, right;

        for (int i = 0; i < n;)
        {
            int j = i;
            while (i < n && s[i] == s[j])
            {
                i++;
            }
            if (s[j] == '0')
            {
                zeros.push_back(i - j);
                left.push_back(j);
                right.push_back(i - 1);
            }
        }

        int m = zeros.size();
        if (m < 2)
        {
            return vector<int>(queries.size(), ones);
        }

        vector<int> temp(m - 1);
        for (int i = 0; i < m - 1; i++)
        {
            temp[i] = zeros[i] + zeros[i + 1];
        }

        SegmentTree seg(temp);
        vector<int> ans;

        for (int i = 0; i < queries.size(); i++)
        {
            int l = lower_bound(right.begin(), right.end(), queries[i][0]) - right.begin(), r = upper_bound(left.begin(), left.end(), queries[i][1]) - left.begin() - 1;
            if (l > m - 1 || r < 0 || l >= r)
            {
                ans.push_back(ones);
                continue;
            }

            int first = right[l] - max(left[l], queries[i][0]) + 1, last = min(right[r], queries[i][1]) - left[r] + 1;
            if (l + 1 == r)
            {
                ans.push_back(ones + first + last);
                continue;
            }

            ans.push_back(ones + max({first + zeros[l + 1], zeros[r - 1] + last, seg.query(l + 1, r - 2)}));
        }

        return ans;
    }
};