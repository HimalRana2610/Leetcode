#include <bits/stdc++.h>
using namespace std;

class Router
{
    map<vector<int>, int> mp;
    queue<vector<int>> q;
    unordered_map<int, vector<int>> timestamps;
    unordered_map<int, int> starttimes;
    int limit = 0;

public:
    Router(int memoryLimit)
    {
        limit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp)
    {
        vector<int> packet = {source, destination, timestamp};
        if (mp.count(packet))
        {
            return false;
        }
        if (q.size() == limit)
        {
            vector<int> res = q.front();
            mp.erase(res);
            int temp = res[1];
            starttimes[temp]++;
            q.pop();
        }

        q.push(packet);
        mp[packet]++;
        timestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket()
    {
        if (q.empty())
        {
            return {};
        }

        vector<int> ans = q.front();
        q.pop();
        mp.erase(ans);
        int temp = ans[1];
        starttimes[temp]++;

        return ans;
    }

    int getCount(int destination, int startTime, int endTime)
    {
        if (timestamps.find(destination) == timestamps.end())
        {
            return 0;
        }

        auto &p = timestamps[destination];
        int temp = starttimes[destination];
        auto right = lower_bound(p.begin() + temp, p.end(), startTime);
        auto left = upper_bound(p.begin() + temp, p.end(), endTime);

        return int(left - right);
    }
};