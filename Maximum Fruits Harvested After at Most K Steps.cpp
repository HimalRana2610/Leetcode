#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        int n = fruits.size();
        vector<int> prefix(n + 1, 0), pos(n);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + fruits[i][1];
            pos[i] = fruits[i][0];
        }

        int ans = 0;
        for (int i = 0; i <= k / 2; i++)
        {
            int start = lower_bound(pos.begin(), pos.end(), startPos - i) - pos.begin(), end = upper_bound(pos.begin(), pos.end(), startPos + k - 2 * i) - pos.begin();
            ans = max(ans, prefix[end] - prefix[start]);

            start = lower_bound(pos.begin(), pos.end(), startPos - (k - 2 * i)) - pos.begin();
            end = upper_bound(pos.begin(), pos.end(), startPos + i) - pos.begin();
            ans = max(ans, prefix[end] - prefix[start]);
        }

        return ans;
    }
};