#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        unordered_map<long long, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        int ans = 0;
        if (freq[1] % 2 == 0)
        {
            ans = freq[1] - 1;
        }
        else
        {
            ans = freq[1];
        }

        freq.erase(1);
        for (auto &f : freq)
        {
            int current = 0;
            long long i = f.first;

            while (freq.contains(i) && freq[i] > 1)
            {
                current += 2;
                i *= i;
            }

            ans = max(ans, current + (freq.contains(i) ? 1 : -1));
        }

        return ans;
    }
};