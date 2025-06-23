#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        int n = s.length();
        vector<string> ans;

        for (int i = 0; i < n; i += k)
        {
            if (i + k <= n)
            {
                ans.push_back(s.substr(i, k));
            }
            else
            {
                string temp = s.substr(i);
                while (temp.length() < k)
                {
                    temp += fill;
                }
                ans.push_back(temp);
            }
        }

        return ans;
    }
};