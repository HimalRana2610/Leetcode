#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool can_assign(vector<int>& tasks, vector<int>& workers, int pills, int strength, int m, int k)
    {
        multiset<int> available(workers.begin() + m - k, workers.end());
        int used = 0;

        for(int i = k - 1; i >= 0; i--)
        {
            auto it = available.lower_bound(tasks[i]);
            if(it != available.end())
            {
                available.erase(it);
            }
            else
            {
                auto it2 = available.lower_bound(tasks[i] - strength);
                if(it2 == available.end() || used == pills)
                {
                    return false;
                }
                used++;
                available.erase(it2);
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength)
    {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int n = tasks.size(), m = workers.size();
        int left = 0, right = min(n, m) + 1;

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(can_assign(tasks, workers, pills, strength, m, mid))
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left - 1;
    }
};