#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findLexSmallestString(string s, int a, int b)
    {
        int n = s.length();
        vector<bool> visited(n, false);
        string ans = s;
        s = s + s;

        for (int i = 0; !visited[i]; i = (i + b) % n)
        {
            visited[i] = true;
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k <= ((b % 2 == 0) ? 0 : 9); k++)
                {
                    string current = s.substr(i, n);
                    for (int l = 1; l < n; l += 2)
                    {
                        current[l] = '0' + (current[l] - '0' + j * a) % 10;
                    }
                    for (int l = 0; l < n; l += 2)
                    {
                        current[l] = '0' + (current[l] - '0' + k * a) % 10;
                    }
                    ans = min(ans, current);
                }
            }
        }

        return ans;
    }
};