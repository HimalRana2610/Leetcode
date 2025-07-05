#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> maxSubsequence(vector<int>& nums, int k)
    {
        vector<int> sorted = nums;
        sort(sorted.rbegin(), sorted.rend());

        int n = sorted.size();
        unordered_map<int, int> freq;

        for(int i = 0; i < n && k > 0; i++, k--)
        {
            freq[sorted[i]]++;
        }

        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(freq[nums[i]] > 0)
            {
                ans.push_back(nums[i]);
                freq[nums[i]]--;
            }
        }

        return ans;
    }
};