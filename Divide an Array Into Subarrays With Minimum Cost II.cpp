#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumCost(vector<int> &nums, int k, int dist)
    {
        int n = nums.size();
        multiset<int> s1, s2;

        long long sum = 0;
        for (int i = 1; i < k - 1; i++)
        {
            if (!s2.empty() && nums[i] >= *s2.begin())
            {
                s2.emplace(nums[i]);
            }
            else
            {
                s1.emplace(nums[i]);
                sum += nums[i];
            }

            while (s1.size() < k - 2 && s2.size() > 0)
            {
                int x = *s2.begin();
                s1.emplace(x);
                sum += x;
                s2.erase(s2.begin());
            }

            while (s1.size() > k - 2)
            {
                int x = *prev(s1.end());
                s2.emplace(x);
                s1.erase(prev(s1.end()));
                sum -= x;
            }
        }

        long long ans = sum + nums[k - 1];
        for (int i = k; i < n; i++)
        {
            int j = i - dist - 1;
            if (j > 0)
            {
                auto it = s1.find(nums[j]);
                if (it != s1.end())
                {
                    s1.erase(it);
                    sum -= nums[j];
                }
                else
                {
                    s2.erase(s2.find(nums[j]));
                }

                while (s1.size() < k - 2 && s2.size() > 0)
                {
                    int x = *s2.begin();
                    s1.emplace(x);
                    sum += x;
                    s2.erase(s2.begin());
                }

                while (s1.size() > k - 2)
                {
                    int x = *prev(s1.end());
                    s2.emplace(x);
                    s1.erase(prev(s1.end()));
                    sum -= x;
                }
            }

            if (!s2.empty() && nums[i - 1] >= *s2.begin())
            {
                s2.emplace(nums[i - 1]);
            }
            else
            {
                s1.emplace(nums[i - 1]);
                sum += nums[i - 1];
            }

            while (s1.size() < k - 2 && s2.size() > 0)
            {
                int x = *s2.begin();
                s1.emplace(x);
                sum += x;
                s2.erase(s2.begin());
            }

            while (s1.size() > k - 2)
            {
                int x = *prev(s1.end());
                s2.emplace(x);
                s1.erase(prev(s1.end()));
                sum -= x;
            }

            ans = min(ans, sum + nums[i]);
        }

        return ans + nums[0];
    }
};