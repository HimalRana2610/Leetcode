#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int m = *max_element(nums.begin(), nums.end()), ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += m - nums[i];
        }

        return ans;
    }
};