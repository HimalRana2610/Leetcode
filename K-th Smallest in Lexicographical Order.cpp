#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int between(int n, long long start, long long end)
    {
        int ans = 0;
        while (start <= n)
        {
            ans += min((long long)(n + 1), end) - start;
            start *= 10;
            end *= 10;
        }

        return ans;
    }

    int findKthNumber(int n, int k)
    {
        int current = 1;
        k--;

        while (k > 0)
        {
            int add = between(n, current, current + 1);
            if (add <= k)
            {
                current++;
                k -= add;
            }
            else
            {
                current *= 10;
                k--;
            }
        }

        return current;
    }
};