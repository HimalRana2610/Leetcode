#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 3;
        long long sum = 0;

        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            pq.push(nums[i]);
        }

        vector<long long> arr1(n + 1);
        arr1[0] = sum;

        for (int i = n; i < 2 * n; i++)
        {
            sum += nums[i];
            pq.push(nums[i]);
            sum -= pq.top();
            pq.pop();
            arr1[i - n + 1] = sum;
        }

        long long arr2 = 0;
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 3 * n - 1; i >= 2 * n; i--)
        {
            arr2 += nums[i];
            min_heap.push(nums[i]);
        }

        long long ans = arr1[n] - arr2;
        for (int i = 2 * n - 1; i >= n; i--)
        {
            arr2 += nums[i];
            min_heap.push(nums[i]);
            arr2 -= min_heap.top();
            min_heap.pop();
            ans = min(ans, arr1[i - n] - arr2);
        }

        return ans;
    }
};