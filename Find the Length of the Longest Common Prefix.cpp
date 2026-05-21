#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> children;

    TrieNode()
    {
        children.resize(26, nullptr);
    }
};

class Trie
{
    TrieNode *root = new TrieNode();

public:
    Trie() {}

    void insert(int num)
    {
        string str = to_string(num);
        TrieNode *current = root;

        for (int i = 0; i < str.length(); i++)
        {
            int idx = str[i] - '0';
            if (!current->children[idx])
            {
                current->children[idx] = new TrieNode();
            }
            current = current->children[idx];
        }
    }

    int lcp(int num)
    {
        string str = to_string(num);
        TrieNode *current = root;
        int ans = 0;

        for (int i = 0; i < str.length(); i++)
        {
            int idx = str[i] - '0';
            if (current->children[idx])
            {
                ans++;
                current = current->children[idx];
            }
            else
            {
                break;
            }
        }

        return ans;
    }
};

class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        Trie trie;
        for (int i = 0; i < arr1.size(); i++)
        {
            trie.insert(arr1[i]);
        }

        int ans = 0;
        for (int i = 0; i < arr2.size(); i++)
        {
            ans = max(ans, trie.lcp(arr2[i]));
        }

        return ans;
    }
};