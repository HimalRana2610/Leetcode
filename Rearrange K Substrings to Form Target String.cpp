#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool isPossibleToRearrange(string s, string t, int k)
    {
        int n = s.length();
        if(n % k != 0)
        {
            return false;
        }

        int substr = n / k;
        vector<string> subs, tsubs;
        for(int i = 0; i < n; i += substr)
        {
            subs.push_back(s.substr(i, substr));
            tsubs.push_back(t.substr(i, substr));
        }

        sort(subs.begin(), subs.end());
        sort(tsubs.begin(), tsubs.end());

        return subs == tsubs;
    }
};