#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<long long> minPrefix(k, LLONG_MAX);
        long long ans = LLONG_MIN;

        for (int i = 0; i <= n; i++)
        {
            if (minPrefix[i % k] != LLONG_MAX)
            {
                ans = max(ans, prefix[i] - minPrefix[i % k]);
            }

            minPrefix[i % k] = min(minPrefix[i % k], prefix[i]);
        }

        return ans;
    }
};