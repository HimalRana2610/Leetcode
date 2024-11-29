#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int set_bits(int n)
    {
        int count = 0;
        while(n)
        {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    bool canSortArray(vector<int>& nums)
    {
        if(nums.size() < 2)
        {
            return true;
        }
        vector<int> sb(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            sb[i] = set_bits(nums[i]);
        }

        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(is_sorted(nums.begin(), nums.end()))
            {
                return true;
            }

            if((nums[i] > nums[i + 1]) && (sb[i] == sb[i + 1]))
            {
                swap(nums[i], nums[i + 1]);
                i = -1;
            }
        }
        return false;
    }
};