#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int shortestSubarray(vector<int>& nums, int k)
    {
        vector<long long> prefix(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = INT_MAX;
        deque<int> dq;

        for(int i = 0; i <= nums.size(); i++)
        {
            while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k)
            {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefix[i] <= prefix[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        if(ans == INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};