#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> child = vector<TrieNode *>(26, nullptr);
    bool is_word = false;

    TrieNode() {}
};

class Trie
{
    TrieNode *root = new TrieNode();

public:
    Trie() {}

    void insert(string word)
    {
        TrieNode *ptr = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!ptr->child[word[i] - 'a'])
            {
                ptr->child[word[i] - 'a'] = new TrieNode();
            }
            ptr = ptr->child[word[i] - 'a'];
        }
        ptr->is_word = true;
    }

    bool search(string word)
    {
        TrieNode *ptr = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!ptr->child[word[i] - 'a'])
            {
                return false;
            }
            ptr = ptr->child[word[i] - 'a'];
        }

        return ptr->is_word;
    }

    bool startsWith(string prefix)
    {
        TrieNode *ptr = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!ptr->child[prefix[i] - 'a'])
            {
                return false;
            }
            ptr = ptr->child[prefix[i] - 'a'];
        }

        return true;
    }
};