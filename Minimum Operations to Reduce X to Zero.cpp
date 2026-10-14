#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size(), total = accumulate(nums.begin(), nums.end(), 0), target = total - x;
        if (target < 0)
        {
            return -1;
        }
        if (target == 0)
        {
            return n;
        }

        int left = 0, sum = 0, m = -1;
        for (int right = 0; right < n; right++)
        {
            sum += nums[right];
            while (left <= right && sum > target)
            {
                sum -= nums[left];
                left++;
            }

            if (sum == target)
            {
                m = max(m, right - left + 1);
            }
        }

        if (m == -1)
        {
            return -1;
        }

        return n - m;
    }
};