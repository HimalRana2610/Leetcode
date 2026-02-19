#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestBalanced(string s)
    {
        int n = s.length(), ans = 1;
        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++)
            {
                bool flag = true;
                freq[s[j] - 'a']++;

                for (int k = 0; k < 26; k++)
                {
                    if (freq[k] > 0 && freq[k] != freq[s[j] - 'a'])
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};