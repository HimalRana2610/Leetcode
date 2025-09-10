#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int makeTheIntegerZero(int num1, int num2)
    {
        for (int i = 1; i <= (long long)num1 - (long long)num2 * i; i++)
        {
            if (i >= __builtin_popcountll((long long)num1 - (long long)num2 * i))
            {
                return i;
            }
        }

        return -1;
    }
};