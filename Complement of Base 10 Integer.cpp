#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        if (n == 0)
        {
            return 1;
        }

        string binary;
        while (n > 0)
        {
            binary.push_back(n % 2 ? '1' : '0');
            n >>= 1;
        }

        int ans = 0;
        for (int i = 0; i < binary.size(); i++)
        {
            if (binary[i] == '0')
            {
                ans += (1 << i);
            }
        }

        return ans;
    }
};