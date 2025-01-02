#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxScoreSightseeingPair(vector<int>& values)
    {
        int ans = 0, m = values[0];
        for(int i = 1; i < values.size(); i++)
        {
            ans = max(ans, m + values[i] - i);
            m = max(m, values[i] + i);
        }
        return ans;
    }
};