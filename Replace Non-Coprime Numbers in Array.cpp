#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        stack<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!s.empty())
            {
                int top = s.top(), gcd = __gcd(top, nums[i]);
                if (gcd == 1)
                {
                    break;
                }

                s.pop();
                nums[i] = (long long)top / gcd * nums[i];
            }
            s.push(nums[i]);
        }

        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};