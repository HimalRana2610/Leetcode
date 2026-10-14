#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minInsertions(string s)
    {
        int cnt = 0, ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                cnt++;
            }
            else
            {
                if (i + 1 < s.length())
                {
                    if (s[i + 1] == ')')
                    {
                        if (cnt > 0)
                        {
                            cnt--;
                        }
                        else
                        {
                            ans++;
                        }
                        i++;
                    }
                    else
                    {
                        if (cnt > 0)
                        {
                            cnt--;
                            ans++;
                        }
                        else
                        {
                            ans += 2;
                        }
                    }
                }
                else
                {
                    if (cnt > 0)
                    {
                        cnt--;
                        ans++;
                    }
                    else
                    {
                        ans += 2;
                    }
                }
            }
        }

        if (cnt > 0)
        {
            ans += 2 * cnt;
        }

        return ans;
    }
};