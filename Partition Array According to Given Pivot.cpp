#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        vector<int> low, equal, high;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < pivot)
            {
                low.push_back(nums[i]);
            }
            else if(nums[i] == pivot)
            {
                equal.push_back(nums[i]);
            }
            else
            {
                high.push_back(nums[i]);
            }
        }

        low.insert(low.end(), equal.begin(), equal.end());
        low.insert(low.end(), high.begin(), high.end());

        return low;
    }
};