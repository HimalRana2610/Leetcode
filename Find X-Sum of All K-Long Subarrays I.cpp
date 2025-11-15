#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++)
        {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++)
            {
                freq[nums[j]]++;
            }

            vector<pair<int, int>> freqVec;
            for (const auto &f : freq)
            {
                freqVec.emplace_back(f.second, f.first);
            }

            sort(freqVec.begin(), freqVec.end(), greater<pair<int, int>>());
            int current = 0;

            for (int j = 0; j < x && j < freqVec.size(); j++)
            {
                current += freqVec[j].first * freqVec[j].second;
            }

            ans.push_back(current);
        }

        return ans;
    }
};