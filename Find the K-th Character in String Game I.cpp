#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char kthCharacter(int k)
    {
        string str = "a";
        while (str.length() < k)
        {
            string temp;
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == 'z')
                {
                    temp.push_back('a');
                }
                else
                {
                    temp.push_back(str[i] + 1);
                }
            }
            str += temp;
        }

        return str[k - 1];
    }
};