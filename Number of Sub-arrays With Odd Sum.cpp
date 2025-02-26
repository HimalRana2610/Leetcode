#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int numOfSubarrays(vector<int>& arr)
    {
        int n = arr.size();
        long long ans = 0;

        unordered_map<int, long long> prefixCount;
        prefixCount[0] = 1;

        int prefixSum = 0;
        for(int i = 0; i < n; i++)
        {
            prefixSum += arr[i];
            if (prefixSum % 2 != 0)
            {
                ans += prefixCount[0];
                prefixCount[1]++;
            }
            else
            {
                ans += prefixCount[1];
                prefixCount[0]++;
            }
        }

        return ans % 1000000007;
    }
};