#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int waysToSplitArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(prefix[i + 1] >= prefix[n] - prefix[i + 1])
            {
                ans++;
            }
        }

        return ans;
    }
};