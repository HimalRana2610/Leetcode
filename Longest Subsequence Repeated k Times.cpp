#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_valid(string &s, string &t, int k)
    {
        int j = 0, cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == t[j])
            {
                j++;
                if (j == t.length())
                {
                    j = 0;
                    cnt++;

                    if (cnt == k)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }

        string valid;
        for (int i = 25; i >= 0; i--)
        {
            if (freq[i] >= k)
            {
                valid.push_back('a' + i);
            }
        }

        queue<string> q;
        for (int i = 0; i < valid.length(); i++)
        {
            q.push(string(1, valid[i]));
        }

        string ans;
        while (!q.empty())
        {
            string current = q.front();
            q.pop();

            if (current.length() > ans.length())
            {
                ans = current;
            }

            for (int i = 0; i < valid.length(); i++)
            {
                string next = current + valid[i];
                if (is_valid(s, next, k))
                {
                    q.push(next);
                }
            }
        }

        return ans;
    }
};