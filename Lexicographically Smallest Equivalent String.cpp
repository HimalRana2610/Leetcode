#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    vector<int> parent, rankv;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        rankv.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void unite(int a, int b)
    {
        int ra = find(a), rb = find(b);
        if (ra == rb)
        {
            return;
        }

        if (rankv[ra] < rankv[rb])
        {
            parent[ra] = rb;
        }
        else if (rankv[ra] > rankv[rb])
        {
            parent[rb] = ra;
        }
        else
        {
            parent[rb] = ra;
            rankv[ra]++;
        }
    }
};

class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        UnionFind uf(26);
        for (int i = 0; i < s1.length(); i++)
        {
            uf.unite(s1[i] - 'a', s2[i] - 'a');
        }

        vector<int> smallest(26);
        for (int i = 0; i < 26; i++)
        {
            smallest[i] = i;
        }

        for (int i = 0; i < 26; i++)
        {
            int c = uf.find(i);
            smallest[c] = min(smallest[c], i);
        }

        string ans;
        for (int i = 0; i < baseStr.length(); i++)
        {
            ans.push_back('a' + smallest[uf.find(baseStr[i] - 'a')]);
        }

        return ans;
    }
};