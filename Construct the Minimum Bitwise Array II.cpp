#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int ans = -1, d = 1;
            while ((nums[i] & d) != 0)
            {
                ans = nums[i] - d;
                d <<= 1;
            }
            nums[i] = ans;
        }

        return nums;
    }
};