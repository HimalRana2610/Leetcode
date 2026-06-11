#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
        {
            return 0;
        }

        long long left = 1, right = x, ans = 1;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;

            if (x >= square)
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