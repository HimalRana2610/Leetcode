#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countCommas(long long n)
    {
        if (n < 1000)
        {
            return 0;
        }

        long long ans = 0;
        if (n < 1000000)
        {
            return ans + n - 999;
        }

        ans += 999000;
        if (n < 1000000000)
        {
            return ans + 2 * (n - 999999);
        }

        ans += 1998000000;
        if (n < 1000000000000)
        {
            return ans + 3 * (n - 999999999);
        }

        ans += 2997000000000;
        if (n < 1000000000000000)
        {
            return ans + 4 * (n - 999999999999);
        }

        return ans + 3996000000000005;
    }
};