#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> prefix, suffix, best, len;
    vector<char> lc, rc;

    void merge(int idx)
    {
        int L = 2 * idx, R = 2 * idx + 1;
        len[idx] = len[L] + len[R];
        lc[idx] = lc[L];
        rc[idx] = rc[R];

        prefix[idx] = prefix[L];
        if (prefix[L] == len[L] && rc[L] == lc[R])
        {
            prefix[idx] = len[L] + prefix[R];
        }

        suffix[idx] = suffix[R];
        if (suffix[R] == len[R] && rc[L] == lc[R])
        {
            suffix[idx] = len[R] + suffix[L];
        }

        best[idx] = max(best[L], best[R]);
        if (rc[L] == lc[R])
        {
            best[idx] = max(best[idx], suffix[L] + prefix[R]);
        }
    }

    void build(int idx, int l, int r, string &s)
    {
        if (l == r)
        {
            prefix[idx] = suffix[idx] = best[idx] = len[idx] = 1;
            lc[idx] = rc[idx] = s[l];
            return;
        }

        int mid = (l + r) / 2;
        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);

        merge(idx);
    }

    void update(int idx, int l, int r, int pos, char ch)
    {
        if (l == r)
        {
            lc[idx] = rc[idx] = ch;
            return;
        }

        int mid = (l + r) / 2;
        if (pos <= mid)
        {
            update(2 * idx, l, mid, pos, ch);
        }
        else
        {
            update(2 * idx + 1, mid + 1, r, pos, ch);
        }

        merge(idx);
    }

public:
    SegmentTree(string &s)
    {
        int n = s.size();
        prefix.resize(4 * n);
        suffix.resize(4 * n);
        best.resize(4 * n);
        len.resize(4 * n);
        lc.resize(4 * n);
        rc.resize(4 * n);
        build(1, 0, n - 1, s);
    }

    void update(int pos, char ch, int n)
    {
        update(1, 0, n - 1, pos, ch);
    }

    int query()
    {
        return best[1];
    }
};

class Solution
{
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices)
    {
        int n = s.size();
        SegmentTree st(s);

        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); i++)
        {
            st.update(queryIndices[i], queryCharacters[i], n);
            ans.push_back(st.query());
        }

        return ans;
    }
};