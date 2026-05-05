#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rotatedDigits(int n)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            string s = to_string(i);
            bool valid = true, rotated = false;

            for (char c : s)
            {
                if (c == '3' || c == '4' || c == '7')
                {
                    valid = false;
                    break;
                }
                if (c == '2' || c == '5' || c == '6' || c == '9')
                {
                    rotated = true;
                }
            }

            if (valid && rotated)
            {
                ans++;
            }
        }

        return ans;
    }
};