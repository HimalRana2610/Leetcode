#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bisect_right(vector<vector<int>> &events, int target)
    {
        int left = 0, right = events.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (events[mid][0] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }

    int maxValue(vector<vector<int>> &events, int k)
    {
        int n = events.size();
        vector<vector<int>> dp(k + 1, vector<int>(n + 1));

        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });

        for (int i = n - 1; i >= 0; i--)
        {
            int next = bisect_right(events, events[i][1]);
            for (int j = 1; j <= k; j++)
            {
                dp[j][i] = max(dp[j][i + 1], events[i][2] + dp[j - 1][next]);
            }
        }

        return dp[k][0];
    }
};