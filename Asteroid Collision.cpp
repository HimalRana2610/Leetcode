#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (asteroids[i] > 0)
            {
                st.push(asteroids[i]);
            }
            else
            {
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i]))
                {
                    st.pop();
                }

                if (st.empty() || st.top() < 0)
                {
                    st.push(asteroids[i]);
                }

                if (!st.empty() && st.top() == abs(asteroids[i]))
                {
                    st.pop();
                }
            }
        }

        int n = st.size();
        vector<int> ans(n);

        for (int i = n - 1; !st.empty(); i--, st.pop())
        {
            ans[i] = st.top();
        }

        return ans;
    }
};