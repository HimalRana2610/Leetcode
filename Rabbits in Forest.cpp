#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int numRabbits(vector<int>& answers)
    {
        unordered_map<int,int> freq;
        for(int i = 0; i < answers.size(); i++)
        {
            freq[answers[i] + 1]++;
        }

        int ans = 0;
        for(auto &f : freq)
        {
            ans += ceil((double)f.second / f.first) * f.first;
        }

        return ans;
    }
};