#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int pow(int x, int n)
    {
        int ans = 1;
        while(n > 0)
        {
            if(n % 2 == 1)
            {
                ans = (int)((1L * ans * x) % 1000000007);
            }

            x = (int)((1L * x * x) % 1000000007);
            n /= 2;
        }

        return ans;
    }

    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size(), m = *max_element(nums.begin(), nums.end()) + 1;
        vector<bool> prime(m, true);
        prime[0] = prime[1] = false;

        vector<int> primeScore(m, 0);
        for(int i = 2; i < m; i++)
        {
            if(prime[i])
            {
                for(int j = i; j < m; j += i)
                {
                    primeScore[j]++;
                    prime[j] = false;
                }
            }
        }

        vector<int> next(n, n);
        stack<int> s;

        for(int i = n - 1; i >= 0; i--)
        {
            while(!s.empty() && primeScore[nums[i]] >= primeScore[nums[s.top()]])
            {
                s.pop();
            }

            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        vector<int> prev(n, -1);
        s = stack<int>();

        for(int i = 0; i < n; i++)
        {
            while(!s.empty() && primeScore[nums[i]] > primeScore[nums[s.top()]])
            {
                s.pop();
            }

            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        vector<pair<int, int>> tuples(n);
        for(int i = 0; i < n; i++)
        {
            tuples[i].first = nums[i];
            tuples[i].second = i;
        }

        sort(tuples.rbegin(), tuples.rend());

        int ans = 1;
        for(const auto &t : tuples)
        {
            int num = t.first, i = t.second;
            int operations = min((long long)(i - prev[i]) * (next[i] - i), (long long)k);

            ans = (int)((1L * ans * pow(num, operations)) % 1000000007);
            k -= operations;

            if (k == 0)
            {
                return ans;
            }
        }

        return ans;
    }
};