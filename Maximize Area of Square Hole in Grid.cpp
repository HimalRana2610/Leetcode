#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hc = 1, hm = 1;
        for (int i = 1; i < hBars.size(); i++)
        {
            if (hBars[i] == hBars[i - 1] + 1)
            {
                hc++;
            }
            else
            {
                hc = 1;
            }
            hm = max(hm, hc);
        }

        int vc = 1, vm = 1;
        for (int i = 1; i < vBars.size(); i++)
        {
            if (vBars[i] == vBars[i - 1] + 1)
            {
                vc++;
            }
            else
            {
                vc = 1;
            }
            vm = max(vm, vc);
        }

        return (min(hm, vm) + 1) * (min(hm, vm) + 1);
    }
};