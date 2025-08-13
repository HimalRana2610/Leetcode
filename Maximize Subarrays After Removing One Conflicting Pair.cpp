#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs)
    {
        vector<int> a1(n + 1, INT_MAX), a2(n + 1, INT_MAX);
        for (int i = 0; i < conflictingPairs.size(); i++)
        {
            int mi = min(conflictingPairs[i][0], conflictingPairs[i][1]), ma = max(conflictingPairs[i][0], conflictingPairs[i][1]);
            if (a1[mi] > ma)
            {
                a2[mi] = a1[mi];
                a1[mi] = ma;
            }
            else if (a2[mi] > ma)
            {
                a2[mi] = ma;
            }
        }

        long long ans = 0;
        int i1 = n, i2 = INT_MAX;
        vector<long long> cnt(n + 1, 0);

        for (int i = n; i > 0; i--)
        {
            if (a1[i1] > a1[i])
            {
                i2 = min(i2, a1[i1]);
                i1 = i;
            }
            else
            {
                i2 = min(i2, a1[i]);
            }

            ans += min(a1[i1], n + 1) - i;
            cnt[i1] += min({i2, a2[i1], n + 1}) - min(a1[i1], n + 1);
        }

        return ans + *max_element(cnt.begin(), cnt.end());
    }
};