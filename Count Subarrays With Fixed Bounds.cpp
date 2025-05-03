#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        long long ans = 0, mi = -1, ma = -1, last = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < minK || nums[i] > maxK)
            {
                last = i;
            }
            if(nums[i] == minK)
            {
                mi = i;
            }
            if(nums[i] == maxK)
            {
                ma = i;
            }
            
            ans += max(0LL, min(mi, ma) - last);
        }

        return ans;
    }
};