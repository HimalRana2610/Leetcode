#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](int a, int b)
             { return abs(a) > abs(b); });

        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < (n + 1) / 2; i++)
        {
            ans += (long long)nums[i] * nums[i];
        }
        for (int i = (n + 1) / 2; i < n; i++)
        {
            ans -= (long long)nums[i] * nums[i];
        }

        return ans;
    }
};