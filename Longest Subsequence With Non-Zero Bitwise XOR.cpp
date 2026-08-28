#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        int n = nums.size(), x = 0;
        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                flag = false;
            }

            x ^= nums[i];
        }

        if (flag)
        {
            return 0;
        }

        if (x == 0)
        {
            return n - 1;
        }

        return n;
    }
};