#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sortColors(vector<int>& nums)
    {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        for(int i = 0; i < freq[0]; i++)
        {
            nums[i] = 0;
        }
        for(int i = freq[0]; i < freq[0] + freq[1]; i++)
        {
            nums[i] = 1;
        }
        for(int i = freq[0] + freq[1]; i < nums.size(); i++)
        {
            nums[i] = 2;
        }
    }
};