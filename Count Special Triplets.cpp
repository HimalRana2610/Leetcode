#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialTriplets(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }

        unordered_map<int, int> partial;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int left = partial[nums[i] * 2];
            partial[nums[i]]++;
            int right = freq[nums[i] * 2] - partial[nums[i] * 2];
            ans = (ans + (1LL * left * right % 1000000007)) % 1000000007;
        }

        return ans;
    }
};