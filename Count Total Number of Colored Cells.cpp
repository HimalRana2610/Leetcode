#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long coloredCells(int n)
    {
        long long ans = 1;
        for(int i = 2; i <= n; i++)
        {
            ans += 4 * (i - 2) + 4;
        }

        return ans;
    }
};