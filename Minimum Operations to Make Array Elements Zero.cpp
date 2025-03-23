#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long minOperations(vector<vector<int>>& queries)
    {
        long long ans = 0;
        for(int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0], r = queries[i][1];
            long long current = 0, p = 1;
            for(int j = 0; j < 15; j++)
            {
                long long start = p, end = p * 4 - 1;
                p *= 4;

                if(end < l || start > r)
                {
                    continue;
                }

                long long left = max((long long)l, start), right = min((long long)r, end);
                current += (right - left + 1) * (j + 1);
            }

            ans += (current + 1) / 2;
        }

        return ans;
    }
};