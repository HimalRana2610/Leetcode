#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkStrings(string s1, string s2)
    {
        string odd1, even1;
        for (int i = 0; i < s1.size(); i++)
        {
            if (i % 2 == 0)
            {
                even1 += s1[i];
            }
            else
            {
                odd1 += s1[i];
            }
        }

        sort(odd1.begin(), odd1.end());
        sort(even1.begin(), even1.end());

        string odd2, even2;
        for (int i = 0; i < s2.size(); i++)
        {
            if (i % 2 == 0)
            {
                even2 += s2[i];
            }
            else
            {
                odd2 += s2[i];
            }
        }

        sort(odd2.begin(), odd2.end());
        sort(even2.begin(), even2.end());

        return odd1 == odd2 && even1 == even2;
    }
};