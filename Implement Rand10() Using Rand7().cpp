#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rand10()
    {
        while (true)
        {
            int n = (rand7() - 1) * 7 + rand7();
            if (n <= 40)
            {
                return (n - 1) % 10 + 1;
            }
        }

        return rand7();
    }
};