#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countDays(int days, vector<vector<int>>& meetings)
    {
        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b){return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];});

        int ans = meetings[0][0] - 1, m = meetings[0][1];
        for(int i = 1; i < meetings.size(); i++)
        {
            if(meetings[i][0] > m)
            {
                ans += meetings[i][0] - m - 1;
            }
            m = max(m, meetings[i][1]);
        }
        ans += days - m;

        return ans;
    }
};