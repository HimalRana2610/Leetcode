#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool is_possible(vector<pair<int, int>> intervals)
    {
        sort(intervals.begin(), intervals.end());

        int sections = 0, m = intervals[0].second;
        for(int i = 0; i < intervals.size(); i++)
        {
            if(m <= intervals[i].first)
            {
                sections++;
            }
            m = max(m, intervals[i].second);
        }

        return sections >= 2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles)
    {
        vector<pair<int, int>> x, y;
        for(int i = 0; i < rectangles.size(); i++)
        {
            x.push_back({rectangles[i][0], rectangles[i][2]});
            y.push_back({rectangles[i][1], rectangles[i][3]});
        }

        return is_possible(x) || is_possible(y);;;;
    }
};