#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        if (arr.empty())
        {
            return {};
        }

        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        int n = arr.size(), current = 1;
        unordered_map<int, int> rank;
        rank[sorted[0]] = current++;

        for (int i = 1; i < n; i++)
        {
            if (sorted[i] != sorted[i - 1])
            {
                rank[sorted[i]] = current++;
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = rank[arr[i]];
        }

        return ans;
    }
};