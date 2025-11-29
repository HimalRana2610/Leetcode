#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int cnt = 0;
        bool flag = true;

        int i = 0;
        while (i < nums.size() && nums[i] == 0)
        {
            i++;
        }

        for (i++; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                cnt++;
            }
            else
            {
                if (cnt < k)
                {
                    flag = false;
                    break;
                }
                cnt = 0;
            }
        }

        return flag;
    }
};