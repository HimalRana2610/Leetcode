#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string s, int k)
    {
        int n = s.length(), m = 0;
        vector<set<int>> st(2);

        for (int i = 0; i <= n; i++)
        {
            st[i % 2].insert(i);
            if (i < n && s[i] == '0')
            {
                m++;
            }
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[m] = 0;

        queue<int> q;
        q.push(m);

        st[m % 2].erase(m);
        while (!q.empty())
        {
            m = q.front();
            q.pop();

            int c1 = max(k - n + m, 0), c2 = min(m, k), left = m + k - 2 * c2, right = m + k - 2 * c1;
            for (auto it = st[left % 2].lower_bound(left); it != st[left % 2].end() && *it <= right;)
            {
                int m2 = *it;
                dist[m2] = dist[m] + 1;
                q.push(m2);
                it = next(it);
                st[left % 2].erase(m2);
            }
        }

        return dist[0] == INT_MAX ? -1 : dist[0];
    }
};