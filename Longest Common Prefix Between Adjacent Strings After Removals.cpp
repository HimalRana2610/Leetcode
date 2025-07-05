#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int prefix_length(const string &a, const string &b)
    {
        int n = min(a.length(), b.length());
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                return i;
            }
        }

        return n;
    }

    vector<int> longestCommonPrefix(vector<string> &words)
    {
        int n = words.size();
        vector<int> ans(n, 0);

        if (n <= 2)
        {
            return ans;
        }

        vector<int> lcp(n - 1);
        for (int i = 1; i < n; i++)
        {
            lcp[i - 1] = prefix_length(words[i - 1], words[i]);
        }

        vector<int> prefix(n - 1), suffix(n - 1);
        prefix[0] = lcp[0];
        suffix[n - 2] = lcp[n - 2];

        for (int i = 1; i < n - 1; i++)
        {
            prefix[i] = max(prefix[i - 1], lcp[i]);
        }
        for (int i = n - 3; i >= 0; i--)
        {
            suffix[i] = max(suffix[i + 1], lcp[i]);
        }

        for (int i = 0; i < n; i++)
        {
            int left = (i >= 2 ? prefix[i - 2] : 0), right = (i <= n - 3 ? suffix[i + 1] : 0);
            if (i > 0 && i < n - 1)
            {
                ans[i] = max(max(left, right), prefix_length(words[i - 1], words[i + 1]));
            }
            else
            {
                ans[i] = max(left, right);
            }
        }

        return ans;
    }
};