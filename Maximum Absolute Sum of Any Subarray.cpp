#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxAbsoluteSum(vector<int>& nums)
    {
        int max_sum = 0, min_sum = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            max_sum = max(max_sum, sum);
            min_sum = min(min_sum, sum);
        }

        return max_sum - min_sum;
    }
};