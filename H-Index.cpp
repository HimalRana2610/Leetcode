#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_valid(vector<int> &citations, int idx)
    {
        int cnt = 0;
        for (int i = 0; i < citations.size(); i++)
        {
            if (cnt >= idx)
            {
                return true;
            }

            if (citations[i] >= idx)
            {
                cnt++;
            }
        }

        return cnt >= idx;
    }

    int hIndex(vector<int> &citations)
    {
        int low = 0, high = citations.size(), ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (is_valid(citations, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};