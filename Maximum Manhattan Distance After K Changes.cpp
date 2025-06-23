#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distance(int a, int b, int c)
    {
        return abs(a - b) + c * 2;
    }

    int maxDistance(string str, int k)
    {
        int n = 0, e = 0, w = 0, s = 0, ans = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'N')
            {
                n++;
            }
            else if (str[i] == 'E')
            {
                e++;
            }
            else if (str[i] == 'W')
            {
                w++;
            }
            else if (str[i] == 'S')
            {
                s++;
            }

            int vertical = min(k, min(n, s));
            int horizontal = min(k - vertical, min(e, w));

            ans = max(ans, distance(n, s, vertical) + distance(e, w, horizontal));
        }

        return ans;
    }
};