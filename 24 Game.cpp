#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool backtrack(vector<double> &arr)
    {
        if (arr.size() == 1)
        {
            return fabs(arr[0] - 24.0) < 1e-6;
        }

        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }

                vector<double> next;
                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j)
                    {
                        next.push_back(arr[k]);
                    }
                }

                vector<double> ans = {arr[i] + arr[j], arr[i] - arr[j], arr[j] - arr[i], arr[i] * arr[j]};
                if (fabs(arr[j]) > 1e-6)
                {
                    ans.push_back(arr[i] / arr[j]);
                }
                if (fabs(arr[i]) > 1e-6)
                {
                    ans.push_back(arr[j] / arr[i]);
                }

                for (int k = 0; k < ans.size(); k++)
                {
                    next.push_back(ans[k]);
                    if (backtrack(next))
                    {
                        return true;
                    }
                    next.pop_back();
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int> &cards)
    {
        vector<double> arr(cards.begin(), cards.end());
        return backtrack(arr);
    }
};