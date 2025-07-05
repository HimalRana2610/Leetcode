#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        int n = nums.size(), prev = 0;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == key)
            {
                for (int j = max(prev, i - k); j < min(n, i + k + 1); j++)
                {
                    ans.push_back(j);
                }
                prev = i + k + 1;
            }
        }

        return ans;
    }
};