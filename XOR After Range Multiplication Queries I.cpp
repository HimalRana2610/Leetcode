#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        for (int i = 0; i < queries.size(); i++)
        {
            for (int j = queries[i][0]; j <= queries[i][1]; j += queries[i][2])
            {
                nums[j] = ((long long)nums[j] * queries[i][3]) % 1000000007;
            }
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans ^= nums[i];
        }

        return ans;
    }
};