#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        vector<int> ans, dp;
        for (int i = 0; i < obstacles.size(); i++)
        {
            int l = lower_bound(dp.begin(), dp.end(), obstacles[i] + 1) - dp.begin();
            if (l == dp.size())
            {
                dp.push_back(obstacles[i]);
            }
            else
            {
                dp[l] = obstacles[i];
            }
            ans.push_back(l + 1);
        }
        return ans;
    }
};