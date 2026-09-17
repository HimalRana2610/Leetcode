#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maximumWeight(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> arr;

        for (int i = 0; i < n; i++)
        {
            arr.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }

        sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        vector<vector<long long>> dp(n + 1, vector<long long>(5));
        vector<vector<vector<int>>> indices(n + 1, vector<vector<int>>(5));

        for (int i = 0; i < n; i++)
        {
            int l = arr[i][0], r = arr[i][1], weight = arr[i][2], idx = arr[i][3];
            int k = lower_bound(arr.begin(), arr.begin() + i, l, [](const vector<int> &t, int val)
                                { return t[1] < val; }) -
                    arr.begin();

            for (int j = 1; j < 5; j++)
            {
                long long s1 = dp[i][j], s2 = dp[k][j - 1] + weight;
                if (s1 > s2)
                {
                    dp[i + 1][j] = dp[i][j];
                    indices[i + 1][j] = indices[i][j];
                    continue;
                }

                vector<int> new_idx = indices[k][j - 1];
                new_idx.push_back(idx);

                sort(new_idx.begin(), new_idx.end());

                if (s1 == s2 && indices[i][j] > new_idx)
                {
                    new_idx = indices[i][j];
                }

                dp[i + 1][j] = s2;
                indices[i + 1][j] = new_idx;
            }
        }

        return indices[n][4];
    }
};