#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        int prev = 0, cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                cnt++;
            }
            else
            {
                if (prev >= 2 * k || (prev >= k && cnt >= k))
                {
                    return true;
                }

                prev = cnt;
                cnt = 1;
            }
        }
        if (prev >= 2 * k || cnt >= 2 * k || (prev >= k && cnt >= k))
        {
            return true;
        }

        return false;
    }
};