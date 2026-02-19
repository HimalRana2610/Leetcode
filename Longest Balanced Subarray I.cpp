#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> odds, evens;
            for (int j = i; j < n; j++)
            {
                if (nums[j] % 2 == 0)
                {
                    evens.insert(nums[j]);
                }
                else
                {
                    odds.insert(nums[j]);
                }

                if (odds.size() == evens.size())
                {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};