#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findTheString(vector<vector<int>> &lcp)
    {
        int n = lcp.size();
        string ans(n, '.');
        char current = 'a';

        for (int i = 0; i < n; i++)
        {
            if (ans[i] == '.')
            {
                if (current > 'z')
                {
                    return "";
                }

                ans[i] = current;
                for (int j = i + 1; j < n; j++)
                {
                    if (lcp[i][j] > 0)
                    {
                        ans[j] = ans[i];
                    }
                }

                current++;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (ans[i] != ans[j])
                {
                    if (lcp[i][j])
                    {
                        return "";
                    }
                }
                else
                {
                    if (i == n - 1 || j == n - 1)
                    {
                        if (lcp[i][j] != 1)
                        {
                            return "";
                        }
                    }
                    else
                    {
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1)
                        {
                            return "";
                        }
                    }
                }
            }
        }

        return ans;
    }
};