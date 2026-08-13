#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestNumber(int n, int t)
    {
        for (int i = n;; i++)
        {
            int x = i, p = 1;
            while (x)
            {
                p *= x % 10;
                x /= 10;
            }

            if (p % t == 0)
            {
                return i;
            }
        }

        return -1;
    }
};