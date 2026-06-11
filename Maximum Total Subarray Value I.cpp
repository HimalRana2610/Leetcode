#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        return (long long)k * (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()));
    }
};