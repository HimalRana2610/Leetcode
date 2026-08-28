#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_valid(char ch, string &prefix, string &target, vector<int> &freq, string &odd)
    {
        string left = prefix;
        left.push_back(ch);

        for (int i = 25; i >= 0; i--)
        {
            left.append(freq[i], 'a' + i);
        }

        string palindrome = left + odd, reversed = left;
        reverse(reversed.begin(), reversed.end());
        palindrome += reversed;

        return palindrome > target;
    }

    string lexPalindromicPermutation(string s, string target)
    {
        int n = s.length();
        if (n == 1)
        {
            return s > target ? s : "";
        }

        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }

        string odd = "";
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 == 1)
            {
                if (odd != "")
                {
                    return "";
                }
                odd = string(1, 'a' + i);
            }
            freq[i] /= 2;
        }

        string prefix = "";
        for (int i = 0; i < n / 2; i++)
        {
            bool found = false;
            for (int j = 0; j < 26; j++)
            {
                if (freq[j] == 0)
                {
                    continue;
                }

                freq[j]--;
                if (is_valid('a' + j, prefix, target, freq, odd))
                {
                    prefix.push_back('a' + j);
                    found = true;
                    break;
                }
                else
                {
                    freq[j]++;
                }
            }

            if (!found)
            {
                return "";
            }

            if (prefix[i] > target[i])
            {
                string left = prefix;
                for (int j = 0; j < 26; j++)
                {
                    left.append(freq[j], 'a' + j);
                }

                string palindrome = left + odd, reversed = left;
                reverse(reversed.begin(), reversed.end());
                palindrome += reversed;

                return palindrome;
            }
        }

        string ans = prefix + odd, reversed = prefix;
        reverse(reversed.begin(), reversed.end());
        ans += reversed;

        return ans;
    }
};