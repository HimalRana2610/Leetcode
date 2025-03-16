#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> ans(nums.size(), 0);
        int product = 1, cnt = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                cnt++;
            }
            else
            {
                product *= nums[i];
            }
        }

        if(cnt > 1)
        {
            return ans;
        }
        else if(cnt == 1)
        {
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == 0)
                {
                    ans[i] = product;
                }
            }
        }
        else
        {
            for(int i = 0; i < nums.size(); i++)
            {
                ans[i] = product / nums[i];
            }
        }

        return ans;
    }
};