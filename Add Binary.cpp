#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string addBinary(string a, string b)
    {
        string ans;
        int carry = 0;

        int i = a.length() - 1, j = b.length() - 1;
        while(i >= 0 || j >= 0 || carry)
        {
            int sum = carry;

            if(i >= 0)
            {
                sum += a[i] - '0';
                i--;
            }
            if(j >= 0)
            {
                sum += b[j] - '0';
                j--;
            }

            ans.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};