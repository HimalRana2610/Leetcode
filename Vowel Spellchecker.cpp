#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> case_insensitive, vowel_error;

        for (const string &word : wordlist)
        {
            string lower_word = word;
            transform(lower_word.begin(), lower_word.end(), lower_word.begin(), ::tolower);
            case_insensitive.insert({lower_word, word});

            string devoweled_word = lower_word;
            for (char &ch : devoweled_word)
            {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                {
                    ch = '*';
                }
            }
            vowel_error.insert({devoweled_word, word});
        }

        vector<string> result;
        for (const string &query : queries)
        {
            if (exact.count(query))
            {
                result.push_back(query);
                continue;
            }

            string lower_query = query;
            transform(lower_query.begin(), lower_query.end(), lower_query.begin(), ::tolower);
            if (case_insensitive.count(lower_query))
            {
                result.push_back(case_insensitive[lower_query]);
                continue;
            }

            string devoweled_query = lower_query;
            for (char &ch : devoweled_query)
            {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                {
                    ch = '*';
                }
            }
            if (vowel_error.count(devoweled_query))
            {
                result.push_back(vowel_error[devoweled_query]);
                continue;
            }

            result.push_back("");
        }

        return result;
    }
};