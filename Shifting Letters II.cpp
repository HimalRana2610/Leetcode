#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string shiftingLetters(string s, vector<vector<int>>& shifts)
    {
        int n = s.length();
        vector<int> shift(n + 1, 0);

        for(int i = 0; i < shifts.size(); i++)
        {
            if(shifts[i][2] == 1)
            {
                shift[shifts[i][0]]++;
            }
            else
            {
                shift[shifts[i][0]]--;
            }

            if(shifts[i][1] < n - 1)
            {
                if(shifts[i][2] == 1)
                {
                    shift[shifts[i][1] + 1]--;
                }
                else
                {
                    shift[shifts[i][1] + 1]++;
                }
            }
        }

        int current = 0;
        for(int i = 0; i < n; i++)
        {
            current += shift[i];
            int temp = (s[i] - 'a' + current) % 26;
            if(temp < 0)
            {
                temp += 26;
            }
            s[i] = 'a' + temp;
        }

        return s;
    }
};