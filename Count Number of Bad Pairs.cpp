#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long countBadPairs(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int i = 0; i < n; i++)
        {
            nums[i] = nums[i] - i;
            freq[nums[i]]++;
        }

        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            int current = n - i - freq[nums[i]];
            ans += current;
            freq[nums[i]]--;
        }

        return ans;
    }
};