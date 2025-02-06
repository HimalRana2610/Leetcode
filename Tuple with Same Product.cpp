#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int tupleSameProduct(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                freq[nums[i] * nums[j]]++;
            }
        }

        long long ans = 0;
        for(auto &f : freq)
        {
            ans += (f.second * (f.second - 1)) * 4;
        }

        return ans;
    }
};