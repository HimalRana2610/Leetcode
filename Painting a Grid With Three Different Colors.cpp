#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool valid_vertical(int state, int m)
    {
        int prev = state % 3;
        state /= 3;

        for(int i = 1; i < m; i++)
        {
            int current = state % 3;
            if(current == prev)
            {
                return false;
            }

            prev = current;
            state /= 3;
        }

        return true;
    }

    bool is_compatible(int a, int b, int m)
    {
        for(int i = 0; i < m; i++)
        {
            if(a % 3 == b % 3)
            {
                return false;
            }

            a /= 3;
            b /= 3;
        }

        return true;
    }

    int colorTheGrid(int m, int n)
    {
        vector<int> states;
        int max_state = 1;

        for(int i = 0; i < m; i++)
        {
            max_state *= 3;
        }
        for(int i = 0; i < max_state; i++)
        {
            if(valid_vertical(i, m))
            {
                states.push_back(i);
            }
        }

        int s = states.size();
        vector<vector<int>> transitions(s);

        for(int i = 0; i < s; i++)
        {
            for(int j = 0; j < s; j++)
            {
                if(is_compatible(states[i], states[j], m))
                {
                    transitions[i].push_back(j);
                }
            }
        }

        vector<long long> dp(s, 1), new_dp(s, 0);
        for(int i = 1; i < n; i++)
        {
            fill(new_dp.begin(), new_dp.end(), 0);
            for(int j = 0; j < s; j++)
            {
                long long ways = dp[j];
                if(!ways)
                {
                    continue;
                }

                for(int k : transitions[j])
                {
                    new_dp[k] = (new_dp[k] + ways) % 1000000007;
                }
            }

            dp.swap(new_dp);
        }

        long long ans = 0;
        for(auto x : dp)
        {
            ans = (ans + x) % 1000000007;
        }

        return ans;
    }
};