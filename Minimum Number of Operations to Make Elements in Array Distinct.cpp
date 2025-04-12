#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minimumOperations(vector<int>& nums)
    {
        int ans = 0;
        unordered_set<int> s;

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(s.find(nums[i]) != s.end())
            {
                ans = i / 3 + 1;
                break;
            }
            s.insert(nums[i]);
        }

        return ans;
    }
};