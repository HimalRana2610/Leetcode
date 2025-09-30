#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int m = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            m = max(m, ++freq[nums[i]]);
        }

        int cnt = 0;
        for (auto &f : freq)
        {
            if (f.second == m)
            {
                cnt++;
            }
        }

        return cnt * m;
    }
};