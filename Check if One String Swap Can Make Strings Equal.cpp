#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool areAlmostEqual(string s1, string s2)
    {
        if(s1 == s2)
        {
            return true;
        }

        int n = s1.length(), diff = 0;
        vector<pair<char, char>> arr;

        for(int i = 0; i < n; i++)
        {
            if(s1[i] != s2[i])
            {
                diff++;
                arr.push_back({s1[i], s2[i]});
            }
            if(diff > 2)
            {
                return false;
            }
        }

        return diff == 2 && arr.size() == 2 && arr[0].first == arr[1].second && arr[0].second == arr[1].first;
    }
};