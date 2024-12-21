#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier)
    {
        while(k--)
        {
            *min_element(nums.begin(), nums.end()) *= multiplier;
        }

        return nums;
    }
};