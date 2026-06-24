#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int zigZagArrays(int n, int l, int r)
    {
        int m = r - l + 1;
        vector<int> dp0(m, 0), dp1(m, 0);

        for (int i = 0; i < m; i++)
        {
            dp0[i] = dp1[i] = 1;
        }

        vector<int> prefix0(m + 1, 0), prefix1(m + 1, 0);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefix0[j + 1] = (prefix0[j] + dp0[j]) % 1000000007;
                prefix1[j + 1] = (prefix1[j] + dp1[j]) % 1000000007;
            }

            for (int j = 0; j < m; j++)
            {
                dp0[j] = (prefix1[m] - prefix1[j + 1] + 1000000007) % 1000000007;
                dp1[j] = prefix0[j];
            }
        }

        auto ans0 = reduce(dp0.begin(), dp0.end(), 0, [](int acc, int x)
                           { return (acc + x) % 1000000007; }),
             ans1 = reduce(dp1.begin(), dp1.end(), 0, [](int acc, int x)
                           { return (acc + x) % 1000000007; });
        return (ans0 + ans1) % 1000000007;
    }
};