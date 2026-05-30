#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    vector<int> children;
    int len, idx;

    TrieNode()
    {
        children.assign(26, -1);
        len = 1e9;
        idx = 1e9;
    }
};

class Solution
{
public:
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        vector<TrieNode> trie;
        trie.emplace_back();

        for (int i = 0; i < wordsContainer.size(); i++)
        {
            int l = wordsContainer[i].length(), current = 0;
            if (l < trie[current].len || (l == trie[current].len && i < trie[current].idx))
            {
                trie[current].len = l;
                trie[current].idx = i;
            }

            for (int j = l - 1; j >= 0; j--)
            {
                int idx = wordsContainer[i][j] - 'a';
                if (trie[current].children[idx] == -1)
                {
                    trie[current].children[idx] = trie.size();
                    trie.emplace_back();
                }

                current = trie[current].children[idx];
                if (l < trie[current].len || (l == trie[current].len && i < trie[current].idx))
                {
                    trie[current].len = l;
                    trie[current].idx = i;
                }
            }
        }

        vector<int> ans(wordsQuery.size());
        for (int i = 0; i < wordsQuery.size(); i++)
        {
            int current = 0, l = wordsQuery[i].length();
            for (int j = l - 1; j >= 0; j--)
            {
                int charIdx = wordsQuery[i][j] - 'a';
                if (trie[current].children[charIdx] == -1)
                {
                    break;
                }
                current = trie[current].children[charIdx];
            }
            ans[i] = trie[current].idx;
        }

        return ans;
    }
};