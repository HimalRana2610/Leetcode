#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxTwoEvents(vector<vector<int>>& events)
    {
        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b){return a[1] < b[1];});
        int n = events.size();

        vector<int> dp1(n, 0);
        dp1[0] = events[0][2];
        for(int i = 1; i < n; i++)
        {
            dp1[i] = max(dp1[i - 1], events[i][2]);
        }

        vector<int> dp2(n, 0);
        for(int i = 1; i < n; i++)
        {
            int low = 0, high = i - 1, index = -1;
            while(low <= high)
            {
                int mid = (low + high) / 2;
                if(events[mid][1] < events[i][0])
                {
                    index = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            if(index != -1)
            {
                dp2[i] = max(dp2[i - 1], dp1[index] + events[i][2]);
            }
            else
            {
                dp2[i] = max(dp2[i - 1], events[i][2]);
            }
        }

        return max(dp1[n - 1], dp2[n - 1]);
    }
};