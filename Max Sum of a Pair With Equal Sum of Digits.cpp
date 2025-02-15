#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maximumSum(vector<int>& nums)
    {
        unordered_map<int, vector<int>> digit_sum;
        for(int i = 0; i < nums.size(); i++)
        {
            int n = nums[i], sum = 0;
            while(n > 0)
            {
                sum += n % 10;
                n /= 10;
            }
            digit_sum[sum].push_back(nums[i]);
        }

        int ans = -1;
        for(auto &s : digit_sum)
        {
            if(s.second.size() > 1)
            {
                sort(s.second.begin(), s.second.end(), greater<int>());
                ans = max(ans, s.second[0] + s.second[1]);
            }
        }

        return ans;
    }
};