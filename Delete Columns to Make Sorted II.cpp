#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size(), ans = 0;
        vector<bool> sorted(n - 1, false);

        for (int j = 0; j < strs[0].length(); j++)
        {
            bool del = false;
            for (int i = 1; i < n; i++)
            {
                if (!sorted[i - 1] && strs[i - 1][j] > strs[i][j])
                {
                    del = true;
                    break;
                }
            }

            if (del)
            {
                ans++;
            }
            else
            {
                for (int i = 1; i < n; i++)
                {
                    if (strs[i - 1][j] < strs[i][j])
                    {
                        sorted[i - 1] = true;
                    }
                }
            }
        }

        return ans;
    }
};