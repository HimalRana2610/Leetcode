#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        string digits = "123456789";

        for (int i = 2; i <= 9; i++)
        {
            for (int j = 0; j <= 9 - i; j++)
            {
                string s = digits.substr(j, i);
                int num = stoi(s);

                if (num >= low && num <= high)
                {
                    ans.push_back(num);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};