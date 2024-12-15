#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int buttonWithLongestTime(vector<vector<int>>& events)
    {
        int m = events[0][1], index = events[0][0];
        for(int i = 1; i < events.size(); i++)
        {
            if(events[i][1] - events[i - 1][1] == m)
            {
                index = min(index, events[i][0]);
            }
            else if(events[i][1] - events[i - 1][1] > m)
            {
                m = events[i][1] - events[i - 1][1];
                index = events[i][0];
            }
        }

        return index;
    }
};