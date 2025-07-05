#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int cnt = 1, ans = -1;

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] == arr[i - 1])
            {
                cnt++;
            }
            else
            {
                if (cnt == arr[i - 1])
                {
                    ans = arr[i - 1];
                }
                cnt = 1;
            }
        }

        if (cnt == arr.back())
        {
            ans = arr.back();
        }

        return ans;
    }
};