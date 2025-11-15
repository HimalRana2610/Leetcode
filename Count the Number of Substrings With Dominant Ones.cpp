#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        vector<int> prefix(n + 1);
        prefix[0] = -1;

        for (int i = 0; i < n; i++)
        {
            if (i == 0 || (i > 0 && s[i - 1] == '0'))
            {
                prefix[i + 1] = i;
            }
            else
            {
                prefix[i + 1] = prefix[i];
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int zero = s[i - 1] == '0';
            int j = i;
            while (j > 0 && zero * zero <= n)
            {
                int one = (i - prefix[j]) - zero;
                if (zero * zero <= one)
                {
                    ans += min(j - prefix[j], one - zero * zero + 1);
                }

                j = prefix[j];
                zero++;
            }
        }

        return ans;
    }
};