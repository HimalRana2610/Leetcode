#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string generateString(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();
        for (int i = 0; i < n; i++)
        {
            if (str1[i] == 'T')
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (str1[j] == 'T')
                    {
                        int overlap_start = j, overlap_end = min(i + m - 1, j + m - 1);
                        if (overlap_start <= overlap_end)
                        {
                            int offset_in_i = j - i;
                            for (int k = 0; k <= overlap_end - overlap_start; k++)
                            {
                                if (str2[offset_in_i + k] != str2[k])
                                {
                                    return "";
                                }
                            }
                        }
                    }
                }
            }
        }

        string ans(n + m - 1, 'a');
        for (int i = 0; i < n; i++)
        {
            if (str1[i] == 'T')
            {
                for (int j = 0; j < m; j++)
                {
                    if (ans[i + j] > str2[j])
                    {
                        return "";
                    }

                    ans[i + j] = str2[j];
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (str1[i] == 'F')
            {
                if (ans.substr(i, m) == str2)
                {
                    bool flag = false;
                    for (int j = m - 1; j >= 0; j--)
                    {
                        if (ans[i + j] < 'z')
                        {
                            ans[i + j]++;
                            bool valid = true;

                            for (int k = max(0, (i + j) - m + 1); k <= min(n - 1, i + j); k++)
                            {
                                if (str1[k] == 'T' && ans.substr(k, m) != str2)
                                {
                                    valid = false;
                                    break;
                                }
                            }

                            if (valid)
                            {
                                flag = true;
                                break;
                            }

                            ans[i + j]--;
                        }
                    }

                    if (!flag)
                    {
                        return "";
                    }
                }
            }
        }

        return ans;
    }
};