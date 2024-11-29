#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minimumSubarrayLength(vector<int>& nums, int k)
    {
        vector<int> bits(32, 0);

        int o = 0, l = 0, ans = nums.size() + 1;
        for(int i = 0; i < nums.size(); i++)
        {
            o |= nums[i];
            for(int j = 0; j < 32; j++)
            {
                if(nums[i] & (1 << j))
                {
                    bits[j]++;
                }
            }

            while(l <= i && o >= k)
            {
                ans = min(ans, i - l + 1);

                int uo = 0;
                for(int j = 0; j < 32; j++)
                {
                    if(nums[l] & (1 << j))
                    {
                        bits[j]--;
                    }
                    if(bits[j])
                    {
                        uo |= (1 << j);
                    }
                }
                o = uo;
                l++;
            }
        }

        if(ans > nums.size())
        {
            return -1;
        }

        return ans;
    }
};