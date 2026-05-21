#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return true;
        }

        int n = nums.size(), zero = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (zero == n - 1)
            {
                if (nums[i] >= zero - i)
                {
                    zero = -1;
                }
            }
            else if (zero != -1)
            {
                if (nums[i] > zero - i)
                {
                    zero = -1;
                }
            }
            else
            {
                if (nums[i] == 0)
                {
                    zero = i;
                }
            }
        }

        return zero == -1;
    }
};