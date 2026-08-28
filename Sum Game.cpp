#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool sumGame(string num)
    {
        int n = num.length(), sum0 = 0, sum1 = 0, q0 = 0, q1 = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (num[i] == '?')
            {
                q0++;
            }
            else
            {
                sum0 += num[i] - '0';
            }
        }
        for (int i = n / 2; i < n; i++)
        {
            if (num[i] == '?')
            {
                q1++;
            }
            else
            {
                sum1 += num[i] - '0';
            }
        }

        return ((q0 + q1) & 1) || ((sum0 - sum1) << 1) != (q1 - q0) * 9;
    }
};