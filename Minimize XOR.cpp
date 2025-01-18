#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minimizeXor(int num1, int num2)
    {
        int a = __builtin_popcount(num1), b = __builtin_popcount(num2), ans = num1;
        for(int i = 0; i < 32; i++)
        {
            if(a > b && (1 << i) & num1)
            {
                ans ^= 1 << i;
                a--;
            }
            if(a < b && !((1 << i) & num1))
            {
                ans ^= 1 << i;
                a++;
            }
        }

        return ans;
    }
};