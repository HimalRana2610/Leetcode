#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        while (nums.size() > 1 && nums[0] == nums.back())
        {
            nums.pop_back();
        }

        int n = nums.size();
        int left = 0, right = n - 1, ans = nums[n - 1];

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums[n - 1])
            {
                ans = nums[mid];
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