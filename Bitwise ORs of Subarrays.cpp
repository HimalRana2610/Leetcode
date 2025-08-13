#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        unordered_set<int> ans, current;
        current.insert(0);

        for (int i = 0; i < arr.size(); i++)
        {
            unordered_set<int> next;
            for (auto &x : current)
            {
                next.insert(arr[i] | x);
            }

            next.insert(arr[i]);
            current = next;
            ans.insert(current.begin(), current.end());
        }

        return ans.size();
    }
};