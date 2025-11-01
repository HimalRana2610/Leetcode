#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalMoney(int n)
    {
        vector<int> ans;
        for (int i = 1; ans.size() < n; i++)
        {
            for (int j = i; j <= i + 6; j++)
            {
                ans.push_back(j);
                if (ans.size() == n)
                {
                    break;
                }
            }
        }

        return accumulate(ans.begin(), ans.end(), 0);
    }
};