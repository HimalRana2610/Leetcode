#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long countSubarrays(vector<int>& nums, int k)
    {
        int m = *max_element(nums.begin(), nums.end()), left = 0, window = 0;
        long long ans = 0;

        for(int right = 0; right < nums.size(); right++)
        {
            if(nums[right] == m)
            {
                window++;
            }
            while(window == k)
            {
                if(nums[left] == m)
                {
                    window--;
                }
                left++;
            }
            ans += left;
        }

        return ans;
    }
};