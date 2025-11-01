#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int prev = 0, ans = 0;
        for (int i = 0; i < bank.size(); i++)
        {
            int current = count(bank[i].begin(), bank[i].end(), '1');
            if (current > 0)
            {
                ans += prev * current;
                prev = current;
            }
        }

        return ans;
    }
};