#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string str = to_string(n);
        sort(str.begin(), str.end());

        for (int i = 0; i < 32; i++)
        {
            string temp = to_string(1 << i);
            sort(temp.begin(), temp.end());
            if (temp == str)
            {
                return true;
            }
        }

        return false;
    }
};