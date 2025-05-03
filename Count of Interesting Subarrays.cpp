#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k)
    {
        unordered_map<int, int> freq;
        freq[0] = 1;

        long long current = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            current += (nums[i] % modulo == k) ? 1 : 0;
            int target = (current - k + modulo) % modulo;

            ans += freq[target];
            freq[current % modulo]++;
        }

        return ans;
    }
};