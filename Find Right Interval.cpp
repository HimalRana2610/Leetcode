#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            int left = 0, right = n - 1;
            while (left <= right)
            {
                int j = left + (right - left) / 2;
                if (intervals[j][0] < intervals[i][1])
                {
                    left = j + 1;
                }
                else
                {
                    ans[intervals[i][2]] = intervals[j][2];
                    right = j - 1;
                }
            }
        }

        return ans;
    }
};