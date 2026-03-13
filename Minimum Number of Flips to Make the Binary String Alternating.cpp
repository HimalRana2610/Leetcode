#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlips(string s)
    {
        int n = s.length();
        vector<vector<int>> prefix(n, vector<int>(2));

        for (int i = 0; i < n; i++)
        {
            prefix[i][0] = (i == 0 ? 0 : prefix[i - 1][1]) + (s[i] == '1');
            prefix[i][1] = (i == 0 ? 0 : prefix[i - 1][0]) + (s[i] == '0');
        }

        int ans = min(prefix[n - 1][0], prefix[n - 1][1]);
        if (n % 2 != 0)
        {
            vector<vector<int>> suffix(n, vector<int>(2));
            for (int i = n - 1; i >= 0; i--)
            {
                suffix[i][0] = (i == n - 1 ? 0 : suffix[i + 1][1]) + (s[i] == '1');
                suffix[i][1] = (i == n - 1 ? 0 : suffix[i + 1][0]) + (s[i] == '0');
            }

            for (int i = 0; i < n - 1; i++)
            {
                ans = min(ans, prefix[i][0] + suffix[i + 1][0]);
                ans = min(ans, prefix[i][1] + suffix[i + 1][1]);
            }
        }

        return ans;
    }
};