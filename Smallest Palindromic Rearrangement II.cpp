#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long capped(long long n, long long r)
    {
        if (r < 0 || r > n)
        {
            return 0;
        }

        r = min(r, n - r);
        if (r == 0)
        {
            return 1;
        }

        __int128 ans = 1;
        for (long long i = 1; i <= r; i++)
        {
            ans = ans * (n - r + i) / i;
            if (ans > 1000000)
            {
                return 1000001;
            }
        }

        return (long long)ans;
    }

    long long ways(vector<int> &half)
    {
        int n = half.size();
        long long r = 0;

        for (int i = 0; i < n; i++)
        {
            r += half[i];
        }

        long long ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (half[i] == 0)
            {
                continue;
            }

            ans *= capped(r, half[i]);
            if (ans > 1000000)
            {
                return 1000001;
            }
            r -= half[i];
        }

        return ans;
    }

    string smallestPalindrome(string s, int k)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }

        int l = 0;
        char mid = 0;
        vector<int> half(26);

        for (int i = 0; i < 26; i++)
        {
            half[i] = freq[i] / 2;
            l += half[i];

            if (freq[i] % 2)
            {
                mid = char('a' + i);
            }
        }

        if (ways(half) < k)
        {
            return "";
        }

        string left = "";
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (half[j] == 0)
                {
                    continue;
                }

                half[j]--;
                long long w = ways(half);

                if (w >= k)
                {
                    left += char('a' + j);
                    break;
                }
                else
                {
                    k -= w;
                    half[j]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
        {
            return left + mid + right;
        }

        return left + right;
    }
};