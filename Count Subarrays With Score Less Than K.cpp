#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long countSubarrays(vector<int>& nums, long long k)
    {
        long long ans = 0, sum = 0, last = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while(sum * (i - last) >= k)
            {
                last++;
                sum -= nums[last];
            }
            ans += i - last;
        }

        return ans;
    }
};