#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long long left = 1, right = num;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;

            if (num == square)
            {
                return true;
            }
            else if (num < square)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return false;
    }
};