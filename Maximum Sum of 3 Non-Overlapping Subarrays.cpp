#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k)
    {
        int n = nums.size(), sum = 0;
        for(int i = 0; i < k; i++)
        {
            sum += nums[i];
        }

        vector<int> subarray_sum(n - k + 1, 0);
        subarray_sum[0] = sum;

        for(int i = 1; i <= n - k; i++)
        {
            sum -= nums[i - 1] - nums[i + k - 1];
            subarray_sum[i] = sum;
        }

        vector<int> left(n - k + 1, 0), right(n - k + 1, n - k);
        for(int i = 1; i < n - k + 1; i++)
        {
            if(subarray_sum[i] > subarray_sum[left[i - 1]])
            {
                left[i] = i;
            }
            else
            {
                left[i] = left[i - 1];
            }
        }

        for(int i = n - k - 1; i >= 0; i--)
        {
            if(subarray_sum[i] >= subarray_sum[right[i + 1]])
            {
                right[i] = i;
            }
            else
            {
                right[i] = right[i + 1];
            }
        }

        int m = INT_MIN;
        vector<int> ans(3, -1);

        for(int i = k; i <= n - 2 * k; i++)
        {
            int total = subarray_sum[left[i - k]] + subarray_sum[i] + subarray_sum[right[i + k]];
            if(total > m)
            {
                m = total;
                ans = {left[i - k], i, right[i + k]};
            }
        }

        return ans;
    }
};