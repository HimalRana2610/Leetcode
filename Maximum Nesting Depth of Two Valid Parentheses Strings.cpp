#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        int depth = 0;
        vector<int> ans;

        for (int i = 0; i < seq.size(); i++)
        {
            if (seq[i] == '(')
            {
                ans.push_back((++depth) % 2);
            }
            else
            {
                ans.push_back((depth--) % 2);
            }
        }

        return ans;
    }
};