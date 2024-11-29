#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit)
    {
        int n = nums.size();
        vector<int> ans(n);

        int total = 0;
        for(int i = 0; i < n; i++)
        {
            total ^= nums[i];
        }

        for(int i = n - 1; i >= 0; i--)
        {
            ans[i] = (1 << maximumBit) - 1 ^ total;
            total ^= nums[i];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};