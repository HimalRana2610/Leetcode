#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        int sum = nums[0];
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] != nums[j - 1] + 1)
            {
                break;
            }
            sum += nums[j];
        }

        unordered_set<int> s(nums.begin(), nums.end());
        while (s.find(sum) != s.end())
        {
            sum++;
        }

        return sum;
    }
};