#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_set<int> s1(arr.begin(), arr.end());
        unordered_map<int, int> freq;

        for (int i = 0; i < arr.size(); i++)
        {
            freq[arr[i]]++;
        }

        unordered_set<int> s2;
        for (auto f : freq)
        {
            s2.insert(f.second);
        }

        return s1.size() == s2.size();
    }
};