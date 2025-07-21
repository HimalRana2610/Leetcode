#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long calculate(vector<int> &piles, long long k)
    {
        long long ans = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            ans += (piles[i] + k - 1) / k;
        }

        return ans;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1, right = *max_element(piles.begin(), piles.end()), ans = 0;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            if (calculate(piles, mid) <= h)
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};