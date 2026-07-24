#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int m = *max_element(nums.begin(), nums.end());
        vector<int> freq(m + 1, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        vector<long long> divisible(m + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            for (int j = i; j <= m; j += i)
            {
                divisible[i] += freq[j];
            }
        }

        vector<long long> exact(m + 1, 0);
        for (int i = m; i >= 1; i--)
        {
            exact[i] = (divisible[i] * (divisible[i] - 1)) / 2;
            for (int j = 2 * i; j <= m; j += i)
            {
                exact[i] -= exact[j];
            }
        }

        vector<long long> prefix(m + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            prefix[i] = prefix[i - 1] + exact[i];
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(lower_bound(prefix.begin(), prefix.end(), queries[i] + 1) - prefix.begin());
        }

        return ans;
    }
};