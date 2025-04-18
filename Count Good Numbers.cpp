#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int power(long long base, long long exp)
    {
        int ans = 1;
        while(exp > 0)
        {
            if(exp % 2 != 0)
            {
                ans = (long long)ans * base % 1000000007;
            }
            base = (long long)base * base % 1000000007;
            exp /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n)
    {
        return (long long)power(5, (n + 1) / 2) * power(4, n / 2) % 1000000007;
    }
};