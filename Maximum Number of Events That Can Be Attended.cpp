#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        int n = events.size(), m = 0;
        for(int i = 0; i < n; i++)
        {
            m = max(m, events[i][1]);
        }

        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        int ans = 0;
        for(int i = 0, j = 0; i <= m; i++)
        {
            while(j < n && events[j][0] <= i)
            {
                pq.push(events[j++][1]);
            }
            while(!pq.empty() && pq.top() < i)
            {
                pq.pop();
            }
            if(!pq.empty())
            {
                pq.pop();
                ans++;
            }
        }

        return ans;
    }
};