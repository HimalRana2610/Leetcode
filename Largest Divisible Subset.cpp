#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size(), size = 1, index = 0;
        vector<int> dp(n, 1), prev(n, -1);

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }

            if(dp[i] > size)
            {
                size = dp[i];
                index = i;
            }
        }

        vector<int> ans;
        while(index != -1)
        {
            ans.push_back(nums[index]);
            index = prev[index];
        }

        return ans;
    }
};