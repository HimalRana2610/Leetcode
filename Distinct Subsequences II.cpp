#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distinctSubseqII(string s)
    {
        int n = s.length();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        unordered_map<char, int> last;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = (2 * dp[i - 1]) % 1000000007;
            if (last.find(s[i - 1]) != last.end())
            {
                int lastIndex = last[s[i - 1]];
                dp[i] = (dp[i] - dp[lastIndex - 1] + 1000000007) % 1000000007;
            }

            last[s[i - 1]] = i;
        }

        return (dp[n] - 1 + 1000000007) % 1000000007;
    }
};