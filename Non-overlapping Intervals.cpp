#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int n = intervals.size(), prev = 0, cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= intervals[prev][1])
            {
                prev = i;
                cnt++;
            }
        }

        return n - cnt;
    }
};