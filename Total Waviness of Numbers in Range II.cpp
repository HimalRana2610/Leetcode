#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long count(long long num, int pattern)
    {
        long long type = pattern < 100, ans = 0, mult = 1;
        for (int i = 0; i < 16; i++)
        {
            if (mult * 100 > num)
            {
                break;
            }

            long long prefix = num / (mult * 1000), current = (num / mult) % 1000, suffix = num % mult, ways = 0, edge = 0;
            if (current > pattern)
            {
                ways = prefix - type + 1;
            }
            else if (current == pattern)
            {
                ways = max(0LL, prefix - type);
                edge = (prefix >= type) * (suffix + 1);
            }
            else if (current < pattern)
            {
                ways = max(0LL, prefix - type);
            }

            ans += ways * mult + edge;
            mult *= 10;
        }

        return ans;
    }

    long long solve(long long num, vector<int> &waves)
    {
        if (num < 100)
        {
            return 0;
        }

        long long ans = 0;
        for (auto &w : waves)
        {
            ans += count(num, w);
        }

        return ans;
    }

    long long totalWaviness(long long num1, long long num2)
    {
        vector<int> waves(570);
        for (int i = 0, j = 0; i < 1000; i++)
        {
            int l = (i / 100) % 10, m = (i / 10) % 10, r = i % 10;
            if ((m > max(l, r)) | (m < min(l, r)))
            {
                waves[j++] = i;
            }
        }

        return solve(num2, waves) - solve(num1 - 1, waves);
    }
};