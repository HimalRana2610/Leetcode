#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    string serial;
    unordered_map<string, Trie *> children;
};

class Solution
{
public:
    void construct(Trie *node, unordered_map<string, int> &freq)
    {
        if (node->children.empty())
        {
            return;
        }

        vector<string> keys;
        for (auto &child : node->children)
        {
            construct(child.second, freq);
            keys.push_back(child.first + "(" + child.second->serial + ")");
        }

        sort(keys.begin(), keys.end());
        for (int i = 0; i < keys.size(); i++)
        {
            node->serial += move(keys[i]);
        }

        freq[node->serial]++;
    }

    void operate(Trie *node, unordered_map<string, int> &freq, vector<string> &path, vector<vector<string>> &ans)
    {
        if (freq[node->serial] > 1)
        {
            return;
        }

        if (!path.empty())
        {
            ans.push_back(path);
        }

        for (auto &child : node->children)
        {
            path.push_back(child.first);
            operate(child.second, freq, path, ans);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        Trie *root = new Trie();
        for (int i = 0; i < paths.size(); i++)
        {
            Trie *current = root;
            for (int j = 0; j < paths[i].size(); j++)
            {
                if (!current->children.count(paths[i][j]))
                {
                    current->children[paths[i][j]] = new Trie();
                }
                current = current->children[paths[i][j]];
            }
        }

        unordered_map<string, int> freq;
        construct(root, freq);

        vector<vector<string>> ans;
        vector<string> path;

        operate(root, freq, path, ans);
        return ans;
    }
};