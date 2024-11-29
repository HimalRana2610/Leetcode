#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string compressedString(string word)
    {
        char ch = word[0];
        int count = 1;
        string ans = "";

        for(int i = 1; i < word.length(); i++)
        {
            if(word[i] == ch)
            {
                count++;
            }
            else
            {
                while(count > 9)
                {
                    ans.push_back('9');
                    ans.push_back(ch);
                    count -= 9;
                }
                ans.push_back(count + '0');
                ans.push_back(ch);
                ch = word[i];
                count = 1;
            }
        }

        while(count > 9)
        {
            ans.push_back('9');
            ans.push_back(ch);
            count -= 9;
        }
        ans.push_back(count + '0');
        ans.push_back(ch);

        return ans;
    }
};