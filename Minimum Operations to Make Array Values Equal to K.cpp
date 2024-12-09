#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minOperations(vector<int>& nums, int k)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int m = *min_element(nums.begin(), nums.end());

        if(k > m)
        {
            return -1;
        }
        else if(k == m)
        {
            return s.size() - 1;
        }
        return s.size();
    }
};