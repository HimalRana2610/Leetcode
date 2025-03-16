#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool can_zero(int target, vector<int>& temp)
    {
        if(target == 0)
        {
            return true;
        }

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for(int i = 0; i < temp.size(); i++)
        {
            for(int j = target; j >= temp[i]; j--)
            {
                dp[j] = dp[j] || dp[j - temp[i]];
            }

            if(dp[target])
            {
                return true;
            }
        }

        return dp[target];
    }

    bool is_possible(int k, vector<int>& nums, vector<vector<int>>& queries)
    {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            vector<int> temp;
            for(int j = 0; j < k; j++)
            {
                if(queries[j][0] <= i && i <= queries[j][1])
                {
                    temp.push_back(queries[j][2]);
                }
            }

            if(nums[i] != 0 && !can_zero(nums[i], temp))
            {
                return false;
            }
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        int m = queries.size();
        if(!is_possible(m, nums, queries))
        {
            return -1;
        }

        int l = 0, r = m, ans = m;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(is_possible(mid, nums, queries))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }
};