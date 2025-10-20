#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        vector<int> freq(value, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            freq[((nums[i] % value) + value) % value]++;
        }

        pair<int, int> m = {INT_MAX, -1};
        for (int i = 0; i < value; i++)
        {
            if (freq[i] < m.first)
            {
                m = {freq[i], i};
            }
        }

        if (m.first == 0)
        {
            return m.second;
        }

        return m.first * value + m.second;
    }
};