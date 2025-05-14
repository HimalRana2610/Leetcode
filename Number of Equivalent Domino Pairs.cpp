#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        unordered_map<int, int> freq;
        for(int i = 0; i < dominoes.size(); i++)
        {
            if(dominoes[i][0] > dominoes[i][1])
            {
                swap(dominoes[i][0], dominoes[i][1]);
            }
            freq[dominoes[i][0] * 10 + dominoes[i][1]]++;
        }

        int ans = 0;
        for(auto &f : freq)
        {
            ans += (f.second  * (f.second - 1)) / 2;
        }

        return ans;
    }
};