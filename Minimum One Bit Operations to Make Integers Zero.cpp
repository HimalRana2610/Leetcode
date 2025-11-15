#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        if (n == 0)
        {
            return 0;
        }

        int msb = 1 << (31 - __builtin_clz(n));
        return (2 * msb - 1 - minimumOneBitOperations(n - msb));
    }
};