#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        char ch = chars[0];
        string current = "";
        int count = 1;

        for (int i = 1; i < chars.size(); i++)
        {
            if (chars[i] == ch)
            {
                count++;
            }
            else
            {
                current += ch;
                if (count > 1)
                {
                    current += to_string(count);
                }
                ch = chars[i];
                count = 1;
            }
        }
        current += ch;
        if (count > 1)
        {
            current += to_string(count);
        }

        chars.clear();
        for (int i = 0; i < current.size(); i++)
        {
            chars.push_back(current[i]);
        }

        return current.size();
    }
};