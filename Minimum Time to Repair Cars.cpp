#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool can_repair(vector<int>& ranks, long long time, int cars)
    {
        long long total = 0;
        for(int i = 0; i < ranks.size(); i++)
        {
            total += sqrt(time / ranks[i]);
            if(total >= cars)
            {
                return true;
            }
        }

        return false;
    }

    long long repairCars(vector<int>& ranks, int cars)
    {
        long long l = 1, r = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        while(l < r)
        {
            long long mid = (l + r) / 2;
            if(can_repair(ranks, mid, cars))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }
};