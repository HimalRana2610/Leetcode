#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long minEnd(int n, int x)
    {
        long long ans = x, last = n - 1, pos = 1;
        while(last)
        {
            if(!(x & pos))
            {
                ans |= (last & 1) * pos;
                last >>= 1;
            }
            pos <<= 1;
        }

        return ans;
    }
};