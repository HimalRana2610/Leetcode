#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeLargestSpecial(string s)
    {
        if (s.empty())
        {
            return s;
        }

        vector<string> subs;
        for (int i = 0, cnt = 0, start = 0; i < s.length(); i++)
        {
            cnt += (s[i] == '1') ? 1 : -1;
            if (cnt == 0)
            {
                subs.push_back("1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) + "0");
                start = i + 1;
            }
        }

        sort(subs.begin(), subs.end(), greater<string>());

        string ans;
        for (int i = 0; i < subs.size(); i++)
        {
            ans += subs[i];
        }

        return ans;
    }
};