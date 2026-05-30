#include <bits/stdc++.h>
using namespace std;

class SnapshotArray
{
    vector<vector<pair<int, int>>> arr;
    int id;

public:
    SnapshotArray(int length)
    {
        arr.resize(length);
        id = 0;

        for (int i = 0; i < length; i++)
        {
            arr[i].push_back({0, 0});
        }
    }

    void set(int index, int val)
    {
        arr[index].push_back({id, val});
    }

    int snap()
    {
        return id++;
    }

    int get(int index, int snap_id)
    {
        return prev(upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, INT_MAX)))->second;
    }
};