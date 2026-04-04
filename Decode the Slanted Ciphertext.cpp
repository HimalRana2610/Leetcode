#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeCiphertext(string encodedText, int rows)
    {
        int n = encodedText.length();
        if (rows == 1)
        {
            return encodedText;
        }

        int cols = n / rows;
        string ans;

        for (int c = 0; c < cols; c++)
        {
            int r = 0, j = c;
            while (r < rows && j < cols)
            {
                ans += encodedText[r * cols + j];
                ++r;
                ++j;
            }
        }

        while (!ans.empty() && ans.back() == ' ')
        {
            ans.pop_back();
        }

        return ans;
    }
};