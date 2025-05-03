#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countLargestGroup(int n)
    {
        unordered_map<int, unordered_set<int>> sets;
        int m = INT_MIN;

        for(int i = 1; i <= n; i++)
        {
            string str = to_string(i);
            int sum = 0;
            for(int j = 0; j < str.size(); j++)
            {
                sum += str[j] - '0';
            }
            sets[sum].insert(i);
            m = max(m, (int)sets[sum].size());
        }

        int ans = 0;
        for(auto &s : sets)
        {
            if(s.second.size() == m)
            {
                ans++;
            }
        }

        return ans;
    }
};