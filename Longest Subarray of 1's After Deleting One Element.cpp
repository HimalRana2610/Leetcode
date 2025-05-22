#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int current = 0;
        bool zero = false;
        vector<int> temp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                current++;
            }
            else
            {
                zero = true;
                temp.push_back(current);
                current = 0;
            }
        }
        temp.push_back(current);

        if (!zero)
        {
            return nums.size() - 1;
        }

        int ans = INT_MIN;
        for (int i = 1; i < temp.size(); i++)
        {
            ans = max(ans, temp[i] + temp[i - 1]);
        }

        return ans;
    }
};