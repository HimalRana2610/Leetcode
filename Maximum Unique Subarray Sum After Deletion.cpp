#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxSum(vector<int>& nums)
    {
        int m = *max_element(nums.begin(), nums.end());
        if(m < 0)
        {
            return m;
        }

        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for(int x : s)
        {
            if(x > 0)
            {
                ans += x;
            }
        }

        return ans;
    }
};