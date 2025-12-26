#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.length();
        vector<int> prefix0(n + 1, 0), prefix1(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix0[i + 1] = prefix0[i] + (customers[i] == 'N' ? 1 : 0);
            prefix1[i + 1] = prefix1[i] + (customers[i] == 'Y' ? 1 : 0);
        }

        int m = INT_MAX, ans = n;
        for (int i = n; i >= 0; i--)
        {
            int penalty = prefix0[i] + (prefix1[n] - prefix1[i]);
            if (penalty <= m)
            {
                m = penalty;
                ans = i;
            }
        }

        return ans;
    }
};