#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int possibleStringCount(string word, int k)
    {
        vector<int> freq;
        int cnt = 1;

        for (int i = 1; i < word.length(); i++)
        {
            if (word[i] == word[i - 1])
            {
                cnt++;
            }
            else
            {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);

        int n = freq.size(), ans = 1;
        for (int i = 0; i < n; i++)
        {
            ans = (static_cast<long long>(ans) * freq[i]) % 1000000007;
        }

        if (n >= k)
        {
            return ans;
        }

        vector<int> dp(k), prefix(k, 1);
        dp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            vector<int> current(k);
            for (int j = 1; j < k; j++)
            {
                current[j] = prefix[j - 1];
                if (j - freq[i] > 0)
                {
                    current[j] = (current[j] - prefix[j - freq[i] - 1] + 1000000007) % 1000000007;
                }
            }

            prefix[0] = current[0];
            for (int j = 1; j < k; j++)
            {
                prefix[j] = (prefix[j - 1] + current[j]) % 1000000007;
            }

            dp = move(current);
        }

        return (ans - prefix[k - 1] + 1000000007) % 1000000007;
    }
};