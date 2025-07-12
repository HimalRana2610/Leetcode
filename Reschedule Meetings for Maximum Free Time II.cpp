#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
    {
        int n = startTime.size(), t1 = 0, t2 = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            int left = (i == 0) ? 0 : endTime[i - 1], right = (i == n - 1) ? eventTime : startTime[i + 1];
            if (endTime[i] - startTime[i] <= t1)
            {
                ans = max(ans, right - left);
            }
            t1 = max(t1, startTime[i] - left);
            ans = max(ans, right - left - endTime[i] + startTime[i]);

            left = (i == n - 1) ? 0 : endTime[n - i - 2];
            right = (i == 0) ? eventTime : startTime[n - i];

            if (endTime[n - i - 1] - startTime[n - i - 1] <= t2)
            {
                ans = max(ans, right - left);
            }
            t2 = max(t2, right - endTime[n - i - 1]);
        }

        return ans;
    }
};