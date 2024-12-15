#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maximumLength(string s)
    {
        map<string, int> freq;
        for(int i = 0; i < s.length(); i++)
        {
            for(int j = i + 1; j <= s.length(); j++)
            {
                freq[s.substr(i, j - i)]++;
            }
        }

        vector<pair<string, int>> arr(freq.begin(), freq.end());
        sort(arr.begin(), arr.end(), [](const pair<string, int> &a, const pair<string, int> &b){return a.second > b.second;});

        int m = arr[0].second, ans = 0;
        if(m < 3)
        {
            return -1;
        }
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i].second >= 3 && all_of(arr[i].first.begin(), arr[i].first.end(), [f = arr[i].first[0]](char ch){return ch == f;}))
            {
                ans = max(ans, (int)arr[i].first.length());
            }
            else if(arr[i].second < 3)
            {
                break;
            }
        }

        return ans;
    }
};