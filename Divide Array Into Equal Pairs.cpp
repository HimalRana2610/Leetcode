#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool divideArray(vector<int>& nums)
    {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        for(auto &f : freq)
        {
            if(f.second % 2 != 0)
            {
                return false;
            }
        }

        return true;
    }
};