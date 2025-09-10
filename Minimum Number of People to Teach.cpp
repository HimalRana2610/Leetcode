#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        unordered_set<int> s;
        for (int i = 0; i < friendships.size(); i++)
        {
            unordered_map<int, int> mp;
            bool flag = false;

            for (int j = 0; j < languages[friendships[i][0] - 1].size(); j++)
            {
                mp[languages[friendships[i][0] - 1][j]] = 1;
            }
            for (int j = 0; j < languages[friendships[i][1] - 1].size(); j++)
            {
                if (mp[languages[friendships[i][1] - 1][j]])
                {
                    flag = true;
                    break;
                }
            }

            if (!flag)
            {
                s.insert(friendships[i][0] - 1);
                s.insert(friendships[i][1] - 1);
            }
        }

        int m = 0;
        vector<int> cnt(n + 1, 0);

        for (int x : s)
        {
            for (int i = 0; i < languages[x].size(); i++)
            {
                cnt[languages[x][i]]++;
                m = max(m, cnt[languages[x][i]]);
            }
        }

        return s.size() - m;
    }
};