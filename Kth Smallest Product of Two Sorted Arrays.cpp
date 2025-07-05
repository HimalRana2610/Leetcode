#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(vector<int> &nums, const long long x, long long threshold)
    {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (x >= 0 && nums[mid] * x <= threshold || x < 0 && nums[mid] * x > threshold)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (x >= 0)
        {
            return left;
        }

        return n - left;
    }

    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        long long left = -1e10, right = 1e10;
        while (left <= right)
        {
            long long mid = (left + right) / 2, cnt = 0;
            for (int i = 0; i < nums1.size(); i++)
            {
                cnt += calculate(nums2, nums1[i], mid);
            }

            if (cnt < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
};