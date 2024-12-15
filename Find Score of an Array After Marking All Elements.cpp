#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long findScore(vector<int>& nums)
    {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }

        vector<bool> marked(n, false);
        long long ans = 0;

        while(!pq.empty())
        {
            int value = pq.top().first;
            int index = pq.top().second;
            pq.pop();

            if(marked[index])
            {
                continue;
            }

            marked[index] = true;
            ans += value;

            if(index > 0 && !marked[index - 1])
            {
                marked[index - 1] = true;
            }
            if(index < n - 1 && !marked[index + 1])
            {
                marked[index + 1] = true;
            }
        }

        return ans;
    }
};