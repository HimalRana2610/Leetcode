#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> countMap;
        long long maxSum = 0, currentSum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            currentSum += nums[i];
            countMap[nums[i]]++;

            if(i >= k)
            {
                currentSum -= nums[i - k];
                countMap[nums[i - k]]--;

                if(countMap[nums[i - k]] == 0)
                {
                    countMap.erase(nums[i - k]);
                }
            }

            if(i >= k - 1 && countMap.size() == k)
            {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};