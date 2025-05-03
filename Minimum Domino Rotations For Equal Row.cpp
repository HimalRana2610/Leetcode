#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        int n = tops.size();
        unordered_map<int, int> top_freq, bottom_freq, same_freq;

        for(int i = 0; i < n; i++)
        {
            top_freq[tops[i]]++;
            bottom_freq[bottoms[i]]++;
            if(tops[i] == bottoms[i])
            {
                same_freq[tops[i]]++;
            }
        }

        int m = -1;
        for(int i = 1; i <= 6; i++)
        {
            if(top_freq[i] + bottom_freq[i] - same_freq[i] == n)
            {
                m = max(m, max(top_freq[i], bottom_freq[i]));
            }
        }

        if(m == -1)
        {
            return -1;
        }

        return n - m;
    }
};