#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestNumber(string num, long long t)
    {
        long long temp = t;
        for (int i = 2; i < 10; i++)
        {
            while (temp % i == 0)
            {
                temp /= i;
            }
        }

        if (temp > 1)
        {
            return "-1";
        }

        int n = num.length(), pos = n - 1;
        vector<long long> rem(n + 1);
        rem[0] = t;

        for (int i = 0; i < n; i++)
        {
            if (num[i] == '0')
            {
                pos = i;
                break;
            }
            rem[i + 1] = rem[i] / __gcd(rem[i], (long long)(num[i] - '0'));
        }

        if (rem[n] == 1)
        {
            return num;
        }

        for (int i = pos; i >= 0; i--)
        {
            while (++num[i] <= '9')
            {
                long long current = rem[i] / __gcd(rem[i], (long long)(num[i] - '0'));
                for (int j = n - 1, k = 9; j > i; j--)
                {
                    while (current % k)
                    {
                        k--;
                    }

                    current /= k;
                    num[j] = '0' + k;
                }

                if (current == 1)
                {
                    return num;
                }
            }
        }

        string ans;
        for (int i = 9; i > 1; i--)
        {
            while (t % i == 0)
            {
                ans += '0' + i;
                t /= i;
            }
        }

        ans += string(max(n + 1 - (int)ans.length(), 0), '1');
        reverse(ans.begin(), ans.end());

        return ans;
    }
};