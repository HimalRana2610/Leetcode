#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long gcdSum(vector<int> &nums)
    {
        int n = nums.size(), m = nums[0];
        vector<int> prefix(n);

        for (int i = 0; i < n; i++)
        {
            m = max(m, nums[i]);
            prefix[i] = __gcd(nums[i], m);
        }

        sort(prefix.begin(), prefix.end());

        long long ans = 0;
        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            ans += __gcd(prefix[i], prefix[j]);
        }

        return ans;
    }
};