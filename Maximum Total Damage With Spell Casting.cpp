#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumTotalDamage(vector<int> &power)
    {
        map<int, int> freq;
        for (int i = 0; i < power.size(); i++)
        {
            freq[power[i]]++;
        }

        vector<pair<int, int>> arr = {{INT_MIN, 0}};
        for (auto &f : freq)
        {
            arr.push_back(f);
        }

        int n = arr.size();
        vector<long long> dp(n, 0);
        long long m = 0;

        for (int i = 1, j = 1; i < n; i++)
        {
            while (i > j && arr[i].first > arr[j].first + 2)
            {
                m = max(m, dp[j++]);
            }
            dp[i] = m + (long long)arr[i].first * arr[i].second;
        }

        long long ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};