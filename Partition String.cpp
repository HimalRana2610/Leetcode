#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> partitionString(string s)
    {
        unordered_set<string> st;
        vector<string> ans;

        int prev = 0;
        for (int i = 0; i < s.length(); i++)
        {
            string str = s.substr(prev, i - prev + 1);
            if (st.find(str) == st.end())
            {
                ans.push_back(str);
                st.insert(str);
                prev = i + 1;
            }
        }

        return ans;
    }
};