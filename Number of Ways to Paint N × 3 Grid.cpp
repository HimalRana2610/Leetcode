#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfWays(int n)
    {
        long long same = 6, diff = 6;
        for (int i = 2; i <= n; i++)
        {
            long long new_same = (2 * same + 2 * diff) % 1000000007, new_diff = (2 * same + 3 * diff) % 1000000007;
            same = new_same;
            diff = new_diff;
        }

        return (same + diff) % 1000000007;
    }
};