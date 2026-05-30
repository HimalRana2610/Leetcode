#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int idx, vector<int> &arr, int d, vector<int> &dp)
    {
        if (dp[idx] != -1)
        {
            return;
        }

        dp[idx] = 1;
        for (int i = idx - 1; i >= 0 && idx - i <= d && arr[idx] > arr[i]; i--)
        {
            dfs(i, arr, d, dp);
            dp[idx] = max(dp[idx], dp[i] + 1);
        }

        for (int i = idx + 1; i < arr.size() && i - idx <= d && arr[i] < arr[idx]; i++)
        {
            dfs(i, arr, d, dp);
            dp[idx] = max(dp[idx], dp[i] + 1);
        }
    }

    int maxJumps(vector<int> &arr, int d)
    {
        int n = arr.size();
        vector<int> dp(n, -1);

        for (int i = 0; i < n; i++)
        {
            dfs(i, arr, d, dp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};