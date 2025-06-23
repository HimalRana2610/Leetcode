#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int valid(vector<int> &nums, int t)
    {
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] - nums[i] <= t)
            {
                ans++;
                i++;
            }
        }

        return ans;
    }

    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.back() - nums[0];
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (valid(nums, mid) >= p)
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