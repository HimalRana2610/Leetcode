#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int n = nums.size(), m = *max_element(nums.begin(), nums.end()), u = 1;
        while (u <= m)
        {
            u <<= 1;
        }

        vector<int> one(u), two(u);
        for (int i = 0; i < n; i++)
        {
            one[nums[i]] = 1;
            for (int j = 0; j < u; j++)
            {
                if (one[j])
                {
                    two[j ^ nums[i]] = 1;
                }
            }
        }

        vector<int> three(u);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < u; j++)
            {
                if (two[j])
                {
                    three[j ^ nums[i]] = 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < u; i++)
        {
            if (three[i])
            {
                ans++;
            }
        }

        return ans;
    }
};