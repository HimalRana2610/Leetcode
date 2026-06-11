#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;

        for (int i = 0; i < asteroids.size(); i++)
        {
            if (asteroids[i] > m)
            {
                return false;
            }
            m += asteroids[i];
        }

        return true;
    }
};