#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> maxNumOfSubstrings(string s)
    {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);

        for (int i = 0; i < n; i++)
        {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; i++)
        {
            if (last[i] == -1)
            {
                continue;
            }

            bool valid = true;
            int left = first[i], right = last[i];

            for (int j = left; j <= right; j++)
            {
                if (first[s[j] - 'a'] < left)
                {
                    valid = false;
                    break;
                }
                right = max(right, last[s[j] - 'a']);
            }

            if (valid)
            {
                intervals.push_back({left, right});
            }
        }

        sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second < b.second; });

        int prev = -1;
        vector<string> ans;

        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i].first > prev)
            {
                ans.push_back(s.substr(intervals[i].first, intervals[i].second - intervals[i].first + 1));
                prev = intervals[i].second;
            }
        }

        return ans;
    }
};