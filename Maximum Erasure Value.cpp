#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_set<int> visited;
        int current = 0, ans = 0;

        for (int i = 0, j = 0; j < nums.size(); j++)
        {
            while (visited.find(nums[j]) != visited.end())
            {
                current -= nums[i];
                visited.erase(nums[i++]);
            }

            current += nums[j];
            visited.insert(nums[j]);
            ans = max(ans, current);
        }

        return ans;
    }
};