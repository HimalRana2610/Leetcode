#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (prefix[i] == prefix[n] - prefix[i + 1])
            {
                return i;
            }
        }

        return -1;
    }
};