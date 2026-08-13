#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int ans = 0, i = -1;
        unordered_map<int, int> freq;

        for (int j = 0; j < nums.size(); j++)
        {
            freq[nums[j]]++;
            while (freq[nums[j]] > k)
            {
                freq[nums[++i]]--;
            }
            ans = max(ans, j - i);
        }

        return ans;
    }
};