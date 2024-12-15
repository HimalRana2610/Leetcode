#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long continuousSubarrays(vector<int>& nums)
    {
        long long start = 0, result = 0;
        unordered_map<int, int> freq;

        for(int end = 0; end < nums.size(); end++)
        {
            freq[nums[end]]++;
            while((*max_element(freq.begin(), freq.end(), [](const pair<int, int>& a, const pair<int, int>& b){return a.first < b.first;})).first - (*min_element(freq.begin(), freq.end(), [](const pair<int, int>& a, const pair<int, int>& b){return a.first < b.first;})).first > 2)
            {
                freq[nums[start]]--;
                if (freq[nums[start]] == 0)
                {
                    freq.erase(nums[start]);
                }
                start++;
            }

            result += (end - start + 1);
        }
        
        return result;
    }
};