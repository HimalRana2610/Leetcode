#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool is_possible(vector<int>& nums, int maxOperations, int penalty)
    {
        int op = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            op += (nums[i] - 1) / penalty;
        }

        return op <= maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations)
    {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(is_possible(nums, maxOperations, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};