#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    void calculate_count(vector<int>& nums, int idx, int current, int maxOR, int &ans)
    {
        if(current == maxOR)
        {
            ans++;
        }

        for(int i = idx; i < nums.size(); i++)
        {
            calculate_count(nums, i + 1, current | nums[i], maxOR, ans);
        }
    }

    int countMaxOrSubsets(vector<int>& nums)
    {
        int maxOR = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            maxOR |= nums[i];
        }

        int ans = 0;
        calculate_count(nums, 0, 0, maxOR, ans);

        return ans;
    }
};