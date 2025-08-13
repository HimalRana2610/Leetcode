#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCollectedFruits(vector<vector<int>> &fruits)
    {
        int n = fruits.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += fruits[i][i];
        }

        vector<int> prev(n, INT_MIN), current(n, INT_MIN);
        prev[n - 1] = fruits[0][n - 1];

        for (int i = 1; i < n - 1; i++)
        {
            for (int j = max(n - 1 - i, i + 1); j < n; j++)
            {
                int m = prev[j];
                if (j > 0)
                {
                    m = max(m, prev[j - 1]);
                }
                if (j < n - 1)
                {
                    m = max(m, prev[j + 1]);
                }
                current[j] = m + fruits[i][j];
            }
            swap(prev, current);
        }

        ans += prev[n - 1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(fruits[i][j], fruits[j][i]);
            }
        }

        fill(prev.begin(), prev.end(), INT_MIN);
        fill(current.begin(), current.end(), INT_MIN);

        prev[n - 1] = fruits[0][n - 1];
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = max(n - 1 - i, i + 1); j < n; j++)
            {
                int m = prev[j];
                if (j > 0)
                {
                    m = max(m, prev[j - 1]);
                }
                if (j < n - 1)
                {
                    m = max(m, prev[j + 1]);
                }
                current[j] = m + fruits[i][j];
            }
            swap(prev, current);
        }

        return ans + prev[n - 1];
    }
};