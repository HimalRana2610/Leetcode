#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_palindrome(long long x, vector<int> &digit, const int k)
    {
        int len = -1;
        while (x)
        {
            digit[++len] = x % k;
            x /= k;
        }

        for (int i = 0, j = len; i < j; i++, j--)
        {
            if (digit[i] != digit[j])
            {
                return false;
            }
        }

        return true;
    }

    long long kMirror(int k, int n)
    {
        vector<int> digit(100);
        int left = 1, cnt = 0;

        long long ans = 0;
        while (cnt < n)
        {
            int right = left * 10;
            for (int i = 0; i < 2; i++)
            {
                for (int j = left; j < right && cnt < n; j++)
                {
                    long long current = j;
                    int x = (i == 0) ? j / 10 : j;

                    while (x)
                    {
                        current = current * 10 + x % 10;
                        x /= 10;
                    }
                    if (is_palindrome(current, digit, k))
                    {
                        cnt++;
                        ans += current;
                    }
                }
            }

            left = right;
        }

        return ans;
    }
};