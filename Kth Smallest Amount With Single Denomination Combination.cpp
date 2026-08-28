#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findKthSmallest(vector<int> &coins, int k)
    {
        sort(coins.begin(), coins.end());
        vector<int> new_coins;

        for (int i = 0; i < coins.size(); i++)
        {
            bool found = false;
            for (int j = 0; j < new_coins.size(); j++)
            {
                if (coins[i] % new_coins[j] == 0)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                new_coins.push_back(coins[i]);
            }
        }

        coins = new_coins;
        int n = (1 << coins.size());

        vector<int> cnt(n);
        vector<long long> lcm(n, 1);

        long long right = 1LL * coins[0] * k + 1;
        for (int mask = 1; mask < n; mask++)
        {
            int current = mask & (mask - 1), i = __builtin_ctz(mask);
            long long temp = lcm[current] / __gcd(lcm[current], (long long)coins[i]);

            if (temp <= right / coins[i])
            {
                lcm[mask] = temp * coins[i];
            }
            else
            {
                lcm[mask] = right + 1;
            }
        }

        long long left = k;
        while (left < right)
        {
            long long mid = left + (right - left) / 2, current = 0;
            for (int mask = 1; mask < n; mask++)
            {
                if (lcm[mask] > mid)
                {
                    continue;
                }

                if (__builtin_popcount(mask) & 1)
                {
                    current += mid / lcm[mask];
                }
                else
                {
                    current -= mid / lcm[mask];
                }
            }

            if (current >= k)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};