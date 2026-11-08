#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sortPermutation(vector<int> &nums)
    {
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == i)
            {
                continue;
            }
            ans &= nums[i];
        }

        if (ans == INT_MAX)
        {
            return 0;
        }

        return ans;
    }
};