#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        vector<bool> visited(10001, false);
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[nums[i]])
            {
                ans = nums[i];
                break;
            }

            visited[nums[i]] = true;
        }

        return ans;
    }
};