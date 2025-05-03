#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int numberOfArrays(vector<int>& differences, int lower, int upper)
    {
        int n = differences.size();
        vector<long long> hidden(n + 1, 0);

        for(int i = 0; i < n; i++)
        {
            hidden[i + 1] = hidden[i] + differences[i];
        }

        return max((long long)0, (long long)upper - lower - *max_element(hidden.begin(), hidden.end()) + *min_element(hidden.begin(), hidden.end()) + 1);
    }
};