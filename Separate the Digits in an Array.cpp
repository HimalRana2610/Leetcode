#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            stack<int> s;
            while (nums[i] > 0)
            {
                s.push(nums[i] % 10);
                nums[i] /= 10;
            }

            while (!s.empty())
            {
                ans.push_back(s.top());
                s.pop();
            }
        }

        return ans;
    }
};