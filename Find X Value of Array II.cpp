#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int prod;
    array<int, 5> cnt;

    Node() : prod(1)
    {
        cnt.fill(0);
    }
};

class SegmentTree
{
    int n, k;
    vector<Node> seg;

    Node mergeNode(const Node &L, const Node &R)
    {
        Node res;
        res.prod = (long long)L.prod * R.prod % k;

        for (int r = 0; r < k; r++)
        {
            res.cnt[r] += L.cnt[r];
            res.cnt[(long long)L.prod * r % k] += R.cnt[r];
        }

        return res;
    }

    Node makeLeaf(int value)
    {
        Node res;
        res.prod = value % k;
        res.cnt[value % k] = 1;

        return res;
    }

    void build(int p, int l, int r, const vector<int> &nums)
    {
        if (l == r)
        {
            seg[p] = makeLeaf(nums[l]);
            return;
        }

        int mid = (l + r) / 2;
        build(p * 2, l, mid, nums);
        build(p * 2 + 1, mid + 1, r, nums);
        seg[p] = mergeNode(seg[p * 2], seg[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, int value)
    {
        if (l == r)
        {
            seg[p] = makeLeaf(value);
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
        {
            update(p * 2, l, mid, idx, value);
        }
        else
        {
            update(p * 2 + 1, mid + 1, r, idx, value);
        }

        seg[p] = mergeNode(seg[p * 2], seg[p * 2 + 1]);
    }

    Node query(int p, int l, int r, int ql, int qr)
    {
        if (qr < l || r < ql)
        {
            return Node();
        }

        if (ql <= l && r <= qr)
        {
            return seg[p];
        }

        int mid = (l + r) / 2;
        Node left = query(p * 2, l, mid, ql, qr);
        Node right = query(p * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

public:
    SegmentTree(int n, int k) : n(n), k(k), seg(4 * n + 5) {}

    void build(const vector<int> &nums)
    {
        build(1, 0, n - 1, nums);
    }

    void update(int idx, int value)
    {
        update(1, 0, n - 1, idx, value);
    }

    Node query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums, int k, vector<vector<int>> &queries)
    {
        int n = nums.size();
        SegmentTree st(n, k);
        st.build(nums);

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            nums[queries[i][0]] = queries[i][1];
            st.update(queries[i][0], queries[i][1]);
            ans.push_back(st.query(queries[i][2], n - 1).cnt[queries[i][3]]);
        }

        return ans;
    }
};