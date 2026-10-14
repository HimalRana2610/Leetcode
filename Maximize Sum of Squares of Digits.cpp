#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maxSumOfSquares(int num, int sum)
    {
        if ((sum + 8) / 9 > num)
        {
            return "";
        }

        string ans(sum / 9, '9');
        if (ans.length() < num)
        {
            ans.push_back('0' + sum % 9);
        }

        while (ans.length() < num)
        {
            ans.push_back('0');
        }

        return ans;
    }
};