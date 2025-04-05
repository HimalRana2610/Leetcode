#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long putMarbles(vector<int>& weights, int k)
    {
        int n = weights.size();
        if(k == n)
        {
            return 0;
        }

        vector<long long> diff;
        for(int i = 0; i < n - 1; i++)
        {
            diff.push_back((long long)weights[i] + weights[i + 1]);
        }

        sort(diff.begin(), diff.end());

        long long min_sum = weights[0] + weights[n - 1];
        for(int i = 0; i < k - 1; i++)
        {
            min_sum += diff[i];
        }

        long long max_sum = weights[0] + weights[n - 1];
        for(int i = diff.size() - 1; k > 1; i--, k--)
        {
            max_sum += diff[i];
        }

        return max_sum - min_sum;
    }
};