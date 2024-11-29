#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minimumSumSubarray(vector<int>& nums, int l, int r)
    {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        long long ans = numeric_limits<long long>::max();
        for(int i = l - 1; i < n; i++)
        {
            for(int j = l; j <= r; j++)
            {
                if(i - j + 1 < 0)
                {
                    continue;
                }
                long long temp = prefix[i + 1] - prefix[i - j + 1];
                if(temp > 0)
                {
                    ans = min(ans, temp);
                }
            }
        }

        if(ans == numeric_limits<long long>::max())
        {
            return -1;
        }
        return ans;
    }
};