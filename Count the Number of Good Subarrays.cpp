#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long countGood(vector<int>& nums, int k)
    {
        int n = nums.size(), l = 0, r = -1, equal = 0;
        unordered_map<int, int> freq;

        long long ans = 0;
        while(l < n)
        {
            while(equal < k && r + 1 < n)
            {
                equal += freq[nums[++r]]++;
            }
            if(equal >= k)
            {
                ans += n - r;
            }

            equal -= --freq[nums[l++]];
        }

        return ans;
    }
};