#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> constructTransformedArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++)
        {
            int t = (i + nums[i]) % n;
            if(t < 0)
            {
                t += n;
            }
            ans[i] = nums[t];
        }

        return ans;
    }
};