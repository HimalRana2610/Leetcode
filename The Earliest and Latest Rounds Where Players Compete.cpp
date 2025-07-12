#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> solve(int n, int f, int s, vector<vector<vector<int>>> &dp0, vector<vector<vector<int>>> &dp1)
    {
        if (dp0[n][f][s])
        {
            return {dp0[n][f][s], dp1[n][f][s]};
        }
        if (f + s == n + 1)
        {
            return {1, 1};
        }
        if (f + s > n + 1)
        {
            tie(dp0[n][f][s], dp1[n][f][s]) = solve(n, n + 1 - s, n + 1 - f, dp0, dp1);
            return {dp0[n][f][s], dp1[n][f][s]};
        }

        int earliest = INT_MAX, latest = INT_MIN;
        if (s <= (n + 1) / 2)
        {
            for (int i = 0; i < f; i++)
            {
                for (int j = 0; j < s - f; j++)
                {
                    pair<int, int> current = solve((n + 1) / 2, i + 1, i + j + 2, dp0, dp1);
                    earliest = min(earliest, current.first);
                    latest = max(latest, current.second);
                }
            }
        }
        else
        {
            for (int i = 0; i < f; i++)
            {
                for (int j = 0; j <= n - f - s; j++)
                {
                    pair<int, int> current = solve((n + 1) / 2, i + 1, i + j + (2 * s - n - 1) / 2 + 2, dp0, dp1);
                    earliest = min(earliest, current.first);
                    latest = max(latest, current.second);
                }
            }
        }

        dp0[n][f][s] = earliest + 1;
        dp1[n][f][s] = latest + 1;

        return {dp0[n][f][s], dp1[n][f][s]};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer)
    {
        if (firstPlayer > secondPlayer)
        {
            swap(firstPlayer, secondPlayer);
        }

        vector<vector<vector<int>>> dp0(29, vector<vector<int>>(29, vector<int>(29, 0))), dp1(29, vector<vector<int>>(29, vector<int>(29, 0)));
        pair<int, int> ans = solve(n, firstPlayer, secondPlayer, dp0, dp1);

        return {ans.first, ans.second};
    }
};