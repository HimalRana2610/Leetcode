#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool power(vector<int>& temp)
    {
        for(int i = 1; i < temp.size(); i++)
        {
            if(temp[i] != temp[i - 1] + 1)
            {
                return false;
            }
        }
        return true;
    }

    vector<int> resultsArray(vector<int>& nums, int k)
    {
        vector<int> ans(nums.size() - k + 1, -1);
        for(int i = 0; i < nums.size() - k; i++)
        {
            vector<int> temp(nums.begin() + i, nums.begin() + i + k);
            if(power(temp))
            {
                ans[i] = nums[i + k - 1];
            }
        }

        return ans;
    }
};