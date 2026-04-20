#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reversee(int x)
    {
        int y = 0;
        while (x > 0)
        {
            y = y * 10 + x % 10;
            x /= 10;
        }

        return y;
    }

    int mirrorDistance(int n)
    {
        return abs(n - reversee(n));
    }
};