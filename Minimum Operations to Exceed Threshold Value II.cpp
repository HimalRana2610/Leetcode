#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minOperations(vector<int>& nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        long long ans = 0;

        while(!pq.empty())
        {
            if(pq.top() >= k)
            {
                return ans;
            }

            ans++;
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(2 * min(x, y) + max(x, y));
        }

        return ans;
    }
};