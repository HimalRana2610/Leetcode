#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arrangeCoins(int n)
    {
        long long left = 1, right = n, ans = 1;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long required = (mid * (mid + 1)) / 2;

            if (required <= n)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};