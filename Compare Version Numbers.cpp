#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<int> v1, v2;
        int p = 0;

        for (int i = 0; i < version1.length(); i++)
        {
            if (version1[i] == '.')
            {
                v1.push_back(stoi(version1.substr(p, i - p)));
                p = i + 1;
            }
        }
        v1.push_back(stoi(version1.substr(p)));

        p = 0;
        for (int i = 0; i < version2.length(); i++)
        {
            if (version2[i] == '.')
            {
                v2.push_back(stoi(version2.substr(p, i - p)));
                p = i + 1;
            }
        }
        v2.push_back(stoi(version2.substr(p)));

        while (v1.size() < v2.size())
        {
            v1.push_back(0);
        }

        while (v2.size() < v1.size())
        {
            v2.push_back(0);
        }

        int ans = 0;
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] > v2[i])
            {
                ans = 1;
                break;
            }
            else if (v1[i] < v2[i])
            {
                ans = -1;
                break;
            }
        }

        return ans;
    }
};