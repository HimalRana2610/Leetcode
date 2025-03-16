#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool can_rob(vector<int>& nums, int mid, int k)
    {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= mid)
            {
                cnt++;
                i++;
            }
        }

        return cnt >= k;
    }

    int minCapability(vector<int>& nums, int k)
    {
        int left = *min_element(nums.begin(), nums.end()), right = *max_element(nums.begin(), nums.end());
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(can_rob(nums, mid, k))
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