#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int n = senate.length();
        queue<int> r, d;

        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
            {
                r.push(i);
            }
            else
            {
                d.push(i);
            }
        }

        while (!r.empty() && !d.empty())
        {
            if (r.front() < d.front())
            {
                r.push(n++);
            }
            else
            {
                d.push(n++);
            }

            r.pop();
            d.pop();
        }

        if (r.empty())
        {
            return "Dire";
        }

        return "Radiant";
    }
};