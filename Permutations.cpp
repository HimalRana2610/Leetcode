#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        if (n == 1)
        {
            ans.push_back(nums);
            return ans;
        }

        for (int i = 0; i < n; i++)
        {
            vector<int> rem;
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    rem.push_back(nums[j]);
                }
            }

            vector<vector<int>> permutations = permute(rem);
            for (int j = 0; j < permutations.size(); j++)
            {
                permutations[j].insert(permutations[j].begin(), nums[i]);
                ans.push_back(permutations[j]);
            }
        }

        return ans;
    }
};