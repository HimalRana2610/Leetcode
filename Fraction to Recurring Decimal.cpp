#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
        {
            return "0";
        }

        string ans;
        if (numerator < 0 ^ denominator < 0)
        {
            ans += '-';
        }

        long long num = labs(numerator);
        long long den = labs(denominator);

        long long q = num / den, r = num % den;
        ans += to_string(q);

        if (r == 0)
        {
            return ans;
        }

        ans.push_back('.');
        unordered_map<int, int> mp;

        while (r != 0)
        {
            if (mp.find(r) != mp.end())
            {
                ans.insert(mp[r], "(");
                ans.push_back(')');
                break;
            }
            else
            {
                mp[r] = ans.length();
                r *= 10;
                q = r / den;
                r = r % den;
                ans += to_string(q);
            }
        }

        return ans;
    }
};