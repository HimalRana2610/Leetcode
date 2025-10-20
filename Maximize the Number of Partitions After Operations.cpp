#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPartitionsAfterOperations(string s, int k)
    {
        int n = s.length(), temp = 0, mask = 0, cnt = 0;
        vector<vector<int>> l(n, vector<int>(3)), r(n, vector<int>(3));

        for (int i = 1; i < n; i++)
        {
            int bin = 1 << (s[i - 1] - 'a');
            if (!(mask & bin))
            {
                if (++cnt <= k)
                {
                    mask |= bin;
                }
                else
                {
                    temp++;
                    mask = bin;
                    cnt = 1;
                }
            }

            l[i][0] = temp;
            l[i][1] = mask;
            l[i][2] = cnt;
        }

        temp = 0, mask = 0, cnt = 0;
        for (int i = n - 1; i > 0; i--)
        {
            int bin = 1 << (s[i] - 'a');
            if (!(mask & bin))
            {
                if (++cnt <= k)
                {
                    mask |= bin;
                }
                else
                {
                    temp++;
                    mask = bin;
                    cnt = 1;
                }
            }

            r[i - 1][0] = temp;
            r[i - 1][1] = mask;
            r[i - 1][2] = cnt;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int total_mask = l[i][1] | r[i][1], total_cnt = 0;
            while (total_mask)
            {
                total_mask = total_mask & (total_mask - 1);
                total_cnt++;
            }

            if (l[i][2] == k && r[i][2] == k && total_cnt < 26)
            {
                ans = max(ans, l[i][0] + r[i][0] + 3);
            }
            else if (min(total_cnt + 1, 26) <= k)
            {
                ans = max(ans, l[i][0] + r[i][0] + 1);
            }
            else
            {
                ans = max(ans, l[i][0] + r[i][0] + 2);
            }
        }

        return ans;
    }
};