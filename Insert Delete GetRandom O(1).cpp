#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
    vector<int> arr;
    unordered_map<int, int> idx;

public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (idx.find(val) == idx.end())
        {
            arr.push_back(val);
            idx[val] = arr.size() - 1;
            return true;
        }

        return false;
    }

    bool remove(int val)
    {
        if (idx.find(val) != idx.end())
        {
            arr[idx[val]] = arr.back();
            arr.pop_back();
            idx[arr[idx[val]]] = idx[val];
            idx.erase(val);
            return true;
        }

        return false;
    }

    int getRandom()
    {
        return arr[rand() % arr.size()];
    }
};