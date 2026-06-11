#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> leftRightDifference(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++)
        {
            int left = prefix[i], right = prefix[n] - prefix[i + 1];
            ans[i] = abs(left - right);
        }

        return ans;
    }
};