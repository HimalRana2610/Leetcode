#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size(), one = 0, gcd = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                one++;
            }
            gcd = __gcd(gcd, nums[i]);
        }

        if (one > 0)
        {
            return n - one;
        }
        if (gcd > 1)
        {
            return -1;
        }

        int m = n;
        for (int i = 0; i < n; i++)
        {
            gcd = 0;
            for (int j = i; j < n; j++)
            {
                gcd = __gcd(gcd, nums[j]);
                if (gcd == 1)
                {
                    m = min(m, j - i + 1);
                    break;
                }
            }
        }

        return m + n - 2;
    }
};