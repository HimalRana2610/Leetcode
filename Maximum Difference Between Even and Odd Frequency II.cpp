#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDifference(string s, int k)
    {
        int n = s.length(), ans = INT_MIN;
        for (int x = 0; x <= 4; x++)
        {
            for (int y = 0; y <= 4; y++)
            {
                if (x == y)
                {
                    continue;
                }

                vector<int> prefix1(n + 1), prefix2(n + 1);
                for (int i = 0; i < n; i++)
                {
                    prefix1[i + 1] = prefix1[i] + (s[i] - '0' == x);
                    prefix2[i + 1] = prefix2[i] + (s[i] - '0' == y);
                }

                vector<vector<int>> diff = {{INT_MIN, INT_MIN}, {INT_MIN, INT_MIN}};
                int j = 0;

                for (int i = k; i <= n; i++)
                {
                    while (i - j >= k && prefix1[i] > prefix1[j] && prefix2[i] > prefix2[j])
                    {
                        int a = prefix1[j] % 2, b = prefix2[j] % 2;
                        diff[a][b] = max(diff[a][b], prefix2[j] - prefix1[j]);
                        j++;
                    }

                    int a = prefix1[i] % 2, b = prefix2[i] % 2;
                    if (diff[1 - a][b] != INT_MIN)
                    {
                        ans = max(ans, prefix1[i] - prefix2[i] + diff[1 - a][b]);
                    }
                }
            }
        }

        if (ans == INT_MIN)
        {
            return -1;
        }

        return ans;
    }
};