#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1]; });

        int ans = 0, first = -1, second = -1;
        for (int i = 0; i < intervals.size(); i++)
        {
            int start = intervals[i][0], end = intervals[i][1];
            if (second < start)
            {
                ans += 2;
                first = end - 1;
                second = end;
            }
            else if (first < start)
            {
                ans += 1;
                first = second;
                second = end;
            }
        }

        return ans;
    }
};