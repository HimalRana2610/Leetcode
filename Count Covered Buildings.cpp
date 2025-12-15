#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        vector<int> mar(n + 1), mir(n + 1, n + 1), mac(n + 1), mic(n + 1, n + 1);
        for (int i = 0; i < buildings.size(); i++)
        {
            int x = buildings[i][0], y = buildings[i][1];
            mar[y] = max(mar[y], x);
            mir[y] = min(mir[y], x);
            mac[x] = max(mac[x], y);
            mic[x] = min(mic[x], y);
        }

        int ans = 0;
        for (int i = 0; i < buildings.size(); i++)
        {
            int x = buildings[i][0], y = buildings[i][1];
            if (x > mir[y] && x < mar[y] && y > mic[x] && y < mac[x])
            {
                ans++;
            }
        }

        return ans;
    }
};