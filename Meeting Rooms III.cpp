#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        priority_queue<int, vector<int>, greater<int>> unused;
        for (int i = 0; i < n; i++)
        {
            unused.push(i);
        }

        vector<int> cnt(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used;

        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < meetings.size(); i++)
        {
            while (!used.empty() && used.top().first <= meetings[i][0])
            {
                unused.push(used.top().second);
                used.pop();
            }

            if (!unused.empty())
            {
                used.push({meetings[i][1], unused.top()});
                cnt[unused.top()]++;
                unused.pop();
            }
            else
            {
                used.push({used.top().first + meetings[i][1] - meetings[i][0], used.top().second});
                cnt[used.top().second]++;
                used.pop();
            }
        }

        int m = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt[i] > m)
            {
                m = cnt[i];
                ans = i;
            }
        }

        return ans;
    }
};