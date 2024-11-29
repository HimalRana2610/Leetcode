#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countValidSelections(vector<int>& nums)
    {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                int ls = 0, rs = 0;
                for(int j = i - 1; j >= 0; j--)
                {
                    ls += nums[j];
                }
                for(int j = i + 1; j < nums.size(); j++)
                {
                    rs += nums[j];
                }
                if(abs(ls - rs) == 0)
                {
                    ans += 2;
                }
                else if(abs(ls - rs) == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};