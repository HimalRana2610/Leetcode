#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b){return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});
        vector<int> dp;

        for(int i = 0; i < envelopes.size(); i++)
        {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            if(it == dp.end())
            {
                dp.push_back(envelopes[i][1]);
            }
            else
            {
                *it = envelopes[i][1];
            }
        }
        return dp.size();
    }
};