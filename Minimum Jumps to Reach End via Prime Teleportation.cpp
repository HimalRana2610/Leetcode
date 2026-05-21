#include <bits/stdc++.h>
using namespace std;

const int MX = 1000001;
vector<int> factors[MX];

bool initialized = []()
{
    for (int i = 2; i < MX; ++i)
    {
        if (factors[i].empty())
        {
            for (int j = i; j < MX; j += i)
            {
                factors[j].push_back(i);
            }
        }
    }

    return true;
}();

class Solution
{
public:
    int minJumps(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> edges;

        for (int i = 0; i < n; ++i)
        {
            for (int p : factors[nums[i]])
            {
                edges[p].push_back(i);
            }
        }

        vector<bool> seen(n, false);
        seen[0] = true;

        int ans = 0;
        vector<int> q = {0};

        while (true)
        {
            vector<int> new_q;
            for (int i : q)
            {
                if (i == n - 1)
                {
                    return ans;
                }

                if (i > 0 && !seen[i - 1])
                {
                    seen[i - 1] = true;
                    new_q.push_back(i - 1);
                }

                if (i < n - 1 && !seen[i + 1])
                {
                    seen[i + 1] = true;
                    new_q.push_back(i + 1);
                }

                if (factors[nums[i]].size() == 1)
                {
                    int p = nums[i];
                    if (edges.count(p))
                    {
                        for (int j : edges[p])
                        {
                            if (!seen[j])
                            {
                                seen[j] = true;
                                new_q.push_back(j);
                            }
                        }
                        edges[p].clear();
                    }
                }
            }

            q = move(new_q);
            ans++;
        }

        return -1;
    }
};