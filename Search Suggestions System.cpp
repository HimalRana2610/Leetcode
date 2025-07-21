#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> child = vector<TrieNode *>(26, nullptr);
    bool is_word = false;

    TrieNode() {}
};

class Solution
{
public:
    void insert(TrieNode *node, string word)
    {
        TrieNode *ptr = node;
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

    void search(TrieNode *node, string current, vector<string> &ans)
    {
        if (ans.size() == 3)
        {
            return;
        }

        if (node->is_word)
        {
            ans.push_back(current);
        }

        for (int i = 0; i < 26; i++)
        {
            if (node->child[i])
            {
                current.push_back('a' + i);
                search(node->child[i], current, ans);
                current.pop_back();
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < products.size(); i++)
        {
            insert(root, products[i]);
        }

        vector<vector<string>> ans(searchWord.length());
        TrieNode *ptr = root;

        string curr;
        for (int i = 0; i < searchWord.length(); i++)
        {
            curr.push_back(searchWord[i]);
            vector<string> current;

            if (!ptr->child[searchWord[i] - 'a'])
            {
                return ans;
            }

            search(ptr->child[searchWord[i] - 'a'], curr, current);
            ptr = ptr->child[searchWord[i] - 'a'];

            ans[i] = current;
        }

        return ans;
    }
};