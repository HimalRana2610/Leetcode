#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> last;
        for(int i = 0; i < s.length(); i++)
        {
            last[s[i]] = i;
        }

        vector<int> ans;
        for(int i = 0; i < s.length(); )
        {
            int st = i, e = last[s[i]];
            while(i <= e)
            {
                e = max(e, last[s[i++]]);
            }
            ans.push_back(e - st + 1);
        }

        return ans;
    }
};