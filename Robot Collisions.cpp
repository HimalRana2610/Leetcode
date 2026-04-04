#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int n = positions.size();
        vector<vector<int>> robots(n);

        for (int i = 0; i < n; i++)
        {
            robots[i] = {positions[i], healths[i], i, directions[i]};
        }

        sort(robots.begin(), robots.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (robots[i][3] == 'R')
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && robots[i][1] > 0)
                {
                    int j = st.top();

                    if (robots[j][1] < robots[i][1])
                    {
                        robots[i][1] -= 1;
                        robots[j][1] = 0;
                        st.pop();
                    }
                    else if (robots[j][1] == robots[i][1])
                    {
                        robots[j][1] = 0;
                        robots[i][1] = 0;
                        st.pop();
                        break;
                    }
                    else
                    {
                        robots[j][1] -= 1;
                        robots[i][1] = 0;
                        break;
                    }
                }
            }
        }

        vector<pair<int, int>> survivors;
        for (const auto &r : robots)
        {
            if (r[1] > 0)
            {
                survivors.push_back({r[2], r[1]});
            }
        }

        sort(survivors.begin(), survivors.end());

        vector<int> ans;
        for (const auto &p : survivors)
        {
            ans.push_back(p.second);
        }

        return ans;
    }
};