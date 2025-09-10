#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        deque<pair<int, int>> dq1, dq2;
        dq1.push_back({1, 1});

        int know = 1, share = 0;
        for (int i = 2; i <= n; i++)
        {
            if (!dq1.empty() && dq1[0].first == i - delay)
            {
                know = (know - dq1[0].second + 1000000007) % 1000000007;
                share = (share + dq1[0].second) % 1000000007;
                dq2.push_back(dq1[0]);
                dq1.pop_front();
            }
            if (!dq2.empty() && dq2[0].first == i - forget)
            {
                share = (share - dq2[0].second + 1000000007) % 1000000007;
                dq2.pop_front();
            }
            if (!dq2.empty())
            {
                know = (know + share) % 1000000007;
                dq1.push_back({i, share});
            }
        }

        return (know + share) % 1000000007;
    }
};