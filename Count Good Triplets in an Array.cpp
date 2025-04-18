#include<bits/stdc++.h>
using namespace std;

class SegmentTree
{
    int n;
    vector<int> tree;

    void build(vector<int> &arr, int node, int start, int end)
    {
        if(start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(int idx, int val, int node, int start, int end)
    {
        if(start == end)
        {
            tree[node] = val;
        }
        else
        {
            int mid = (start + end) / 2;
            if(idx <= mid)
            {
                update(idx, val, 2 * node + 1, start, mid);
            }
            else
            {
                update(idx, val, 2 * node + 2, mid + 1, end);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query(int l, int r, int node, int start, int end)
    {
        if(l > end || r < start)
        {
            return 0;
        }
        if(l <= start && end <= r)
        {
            return tree[node];
        }

        int mid = (start + end) / 2;
        int left = query(l, r, 2 * node + 1, start, mid), right = query(l, r, 2 * node + 2, mid + 1, end);

        return left + right;
    }

    public:
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void update(int idx, int val)
    {
        update(idx, val, 0, 0, n - 1);
    }

    int query(int l, int r)
    {
        if(l > r)
        {
            return 0;
        }
        return query(l, r, 0, 0, n - 1);
    }
};

class Solution
{
    public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size(), index = 1;
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++)
        {
            mp[nums1[i]] = index++;
        }

        for(int i = 0; i < n; i++)
        {
            nums2[i] = mp[nums2[i]];
        }

        vector<int> left(n, 0), right(n, 1);
        SegmentTree leftTree(left), rightTree(right);

        leftTree.update(nums2[0] - 1, 1);
        rightTree.update(nums2[0] - 1, 0);

        long long ans = 0;
        for(int i = 1; i < n - 1; i++)
        {
            int idx = nums2[i];
            rightTree.update(idx - 1, 0);

            ans += (long long)leftTree.query(0, idx - 2) * rightTree.query(idx, n - 1);
            leftTree.update(idx - 1, 1);
        }

        return ans;
    }
};