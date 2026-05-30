#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
    unordered_map<string, map<int, string>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        mp[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        auto it = mp[key].upper_bound(timestamp);
        if (it == mp[key].begin())
        {
            return "";
        }

        return (--it)->second;
    }
};