#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maximumSwap(int num)
    {
        string numStr = std::to_string(num);
        vector<int> lastIndex(10, -1);

        for (int i = 0; i < numStr.length(); ++i)
        {
            lastIndex[numStr[i] - '0'] = i;
        }

        for(int i = 0; i < numStr.length(); ++i)
        {
            for(int digit = 9; digit > numStr[i] - '0'; --digit)
            {
                if(lastIndex[digit] > i)
                {
                    swap(numStr[i], numStr[lastIndex[digit]]);
                    return stoi(numStr);
                }
            }
        }

        return num;
    }
};