#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
    {
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        hFences.insert(hFences.begin(), 1);
        hFences.push_back(m);
        vFences.insert(vFences.begin(), 1);
        vFences.push_back(n);

        unordered_set<long long> dist;
        for (int i = 0; i < hFences.size(); i++)
        {
            for (int j = i + 1; j < hFences.size(); j++)
            {
                long long distance = (long long)hFences[j] - hFences[i];
                dist.insert(distance);
            }
        }

        long long ma = -1;
        for (int i = 0; i < vFences.size(); i++)
        {
            for (int j = i + 1; j < vFences.size(); j++)
            {
                long long distance = (long long)vFences[j] - vFences[i];
                if (dist.count(distance))
                {
                    ma = max(ma, distance);
                }
            }
        }

        if (ma == -1)
        {
            return -1;
        }

        return (ma % 1000000007 * ma % 1000000007) % 1000000007;
    }
};