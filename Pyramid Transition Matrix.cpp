#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        unordered_map<string, vector<char>> mp;
        for (int i = 0; i < allowed.size(); i++)
        {
            mp[allowed[i].substr(0, 2)].push_back(allowed[i][2]);
        }

        unordered_set<string> dp;
        dp.insert(bottom);

        while (dp.begin()->length() > 1)
        {
            unordered_set<string> next_dp;
            for (const string &curr : dp)
            {
                vector<string> nexts = {""};
                for (int i = 0; i < curr.length() - 1; i++)
                {
                    string key = curr.substr(i, 2);
                    if (!mp.count(key))
                    {
                        nexts.clear();
                        break;
                    }

                    vector<string> new_nexts;
                    for (const string &n : nexts)
                    {
                        for (char c : mp[key])
                        {
                            new_nexts.push_back(n + c);
                        }
                    }

                    nexts = new_nexts;
                }

                for (const string &n : nexts)
                {
                    next_dp.insert(n);
                }
            }

            if (next_dp.empty())
            {
                return false;
            }

            dp = next_dp;
        }

        return true;
    }
};