#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countCompleteSubarrays(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }

        int unique = freq.size(), ans = 0;
        for(int i = 0; i < n; i++)
        {
            unordered_map<int, int> current;
            for(int j = i; j < n; j++)
            {
                current[nums[j]]++;
                if(current.size() == unique)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};