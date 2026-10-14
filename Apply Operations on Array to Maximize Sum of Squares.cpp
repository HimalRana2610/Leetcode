#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSum(vector<int> &nums, int k)
    {
        vector<int> cnt(30, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < 30; j++)
            {
                if (nums[i] & (1 << j))
                {
                    cnt[j]++;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < k; i++)
        {
            long long current = 0;
            for (int j = 29; j >= 0; j--)
            {
                if (cnt[j] > 0)
                {
                    current |= (1LL << j);
                    cnt[j]--;
                }
            }
            ans = (ans + current * current) % 1000000007;
        }

        return ans;
    }
};