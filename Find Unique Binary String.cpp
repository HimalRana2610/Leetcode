#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string findDifferentBinaryString(vector<string>& nums)
    {
        string ans = "";
        for(int i = 0; i < nums.size(); i++)
        {
            ans.push_back(nums[i][i] == '0' ? '1' : '0');
        }

        return ans;
    }
};