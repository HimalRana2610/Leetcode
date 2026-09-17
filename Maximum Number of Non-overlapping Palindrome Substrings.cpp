#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPalindromes(string s, int k)
    {
        int n = s.length();
        vector<vector<bool>> is_palindrome(n, vector<bool>(n));

        for (int l = 1; l <= n; l++)
        {
            for (int i = 0; i + l <= n; ++i)
            {
                int j = i + l - 1;
                is_palindrome[i][j] = s[i] == s[j] && (l <= 2 || is_palindrome[i + 1][j - 1]);
            }
        }

        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1];
            for (int j = 0; j + k <= i; ++j)
            {
                if (is_palindrome[j][i - 1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};