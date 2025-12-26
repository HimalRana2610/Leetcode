#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        sort(capacity.rbegin(), capacity.rend());

        int total = accumulate(apple.begin(), apple.end(), 0), current = 0, ans = 0;
        for (int i = 0; i < capacity.size(); i++)
        {
            if (current >= total)
            {
                break;
            }

            current += capacity[i];
            ans++;
        }

        return ans;
    }
};