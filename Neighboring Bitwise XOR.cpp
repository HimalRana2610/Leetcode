#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool doesValidArrayExist(vector<int>& derived)
    {
        int xor_val = 0;
        for(int i = 0; i < derived.size(); i++)
        {
            xor_val ^= derived[i];
        }

        return xor_val == 0;
    }
};