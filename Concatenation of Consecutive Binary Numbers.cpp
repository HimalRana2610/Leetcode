#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int concatenatedBinary(int n)
    {
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = ((ans << int(log2(i) + 1)) % 1000000007 + i) % 1000000007;
        }

        return ans;
    }
};