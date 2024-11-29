#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int largestCombination(vector<int>& candidates)
    {
        vector<int> ans(32, 0);
        for(int i = 0; i < candidates.size(); i++)
        {
            for(int j = 0; j < 32; j++)
            {
                if(candidates[i] & (1 << j))
                {
                    ans[j]++;
                }
            }
        }

        return *max_element(ans.begin(), ans.end());
    }
};