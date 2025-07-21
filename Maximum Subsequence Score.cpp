#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++)
        {
            arr[i] = {nums2[i], nums1[i]};
        }

        sort(arr.rbegin(), arr.rend());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0, sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (pq.size() == k)
            {
                sum -= pq.top();
                pq.pop();
            }

            sum += arr[i].second;
            pq.push(arr[i].second);

            if (pq.size() == k)
            {
                ans = max(ans, sum * arr[i].first);
            }
        }

        return ans;
    }
};