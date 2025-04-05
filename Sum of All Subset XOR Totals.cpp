#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int XORsum(vector<int>& nums, int index, int current)
    {
        if(index == nums.size())
        {
            return current;
        }

        return XORsum(nums, index + 1, current ^ nums[index]) + XORsum(nums, index + 1, current);
    }

    int subsetXORSum(vector<int>& nums)
    {
        return XORsum(nums, 0, 0);
    }
};