#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumProfit(vector<int> &prices, int k)
    {
        int n = prices.size();
        if (n < 2 || k == 0)
        {
            return 0;
        }

        int m = min(k, n / 2);
        vector<long long> flat(m + 1, LLONG_MIN), longPos(m, LLONG_MIN), shortPos(m, LLONG_MIN);
        flat[0] = 0;

        for (int price : prices)
        {
            vector<long long> nextFlat = flat, nextLong = longPos, nextShort = shortPos;
            for (int t = 0; t < m; ++t)
            {
                if (longPos[t] != LLONG_MIN)
                {
                    nextFlat[t + 1] = max(nextFlat[t + 1], longPos[t] + price);
                }
                if (shortPos[t] != LLONG_MIN)
                {
                    nextFlat[t + 1] = max(nextFlat[t + 1], shortPos[t] - price);
                }

                if (flat[t] != LLONG_MIN)
                {
                    nextLong[t] = max(nextLong[t], flat[t] - price);
                    nextShort[t] = max(nextShort[t], flat[t] + price);
                }
            }

            flat.swap(nextFlat);
            longPos.swap(nextLong);
            shortPos.swap(nextShort);
        }

        return *max_element(flat.begin(), flat.end());
    }
};