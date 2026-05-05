#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool distance_valid(string &s1, string &s2)
    {
        int dist = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            if (dist > 2)
            {
                return false;
            }

            if (s1[i] != s2[i])
            {
                dist++;
            }
        }

        return dist <= 2;
    }

    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
    {
        vector<string> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            for (int j = 0; j < dictionary.size(); j++)
            {
                if (distance_valid(queries[i], dictionary[j]))
                {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }

        return ans;
    }
};