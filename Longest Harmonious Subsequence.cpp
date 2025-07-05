#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq[nums[i] + 1] > 0)
            {
                ans = max(ans, freq[nums[i]] + freq[nums[i] + 1]);
            }
        }

        return ans;
    }
};