#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        vector<int> dp(days.back() + 1, 0);
        unordered_set<int> travel(days.begin(), days.end());

        for(int i = 1; i <= days.back(); i++)
        {
            if(travel.find(i) == travel.end())
            {
                dp[i] = dp[i - 1];
            }
            else
            {
                dp[i] = min(dp[i - 1] + costs[0], min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]));
            }
        }

        return dp[days.back()];
    }
};