#include <bits/stdc++.h>
using namespace std;

struct PairHash
{
    size_t operator()(const pair<int, int> &p) const
    {
        return ((size_t)p.first << 20) ^ p.second;
    }
};

class MovieRentingSystem
{
    unordered_map<pair<int, int>, int, PairHash> price;
    unordered_map<int, set<pair<int, int>>> unrented;
    set<tuple<int, int, int>> rented;

public:
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (int i = 0; i < entries.size(); i++)
        {
            int shop = entries[i][0], movie = entries[i][1], p = entries[i][2];
            price[{shop, movie}] = p;
            unrented[movie].insert({p, shop});
        }
    }

    vector<int> search(int movie)
    {
        vector<int> ans;
        if (unrented.count(movie))
        {
            int cnt = 0;
            for (auto &m : unrented[movie])
            {
                ans.push_back(m.second);
                if (++cnt == 5)
                {
                    break;
                }
            }
        }

        return ans;
    }

    void rent(int shop, int movie)
    {
        int p = price[{shop, movie}];
        unrented[movie].erase({p, shop});
        rented.insert({p, shop, movie});
    }

    void drop(int shop, int movie)
    {
        int p = price[{shop, movie}];
        rented.erase({p, shop, movie});
        unrented[movie].insert({p, shop});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> ans;
        int cnt = 0;

        for (auto &t : rented)
        {
            int p = get<0>(t), shop = get<1>(t), movie = get<2>(t);
            ans.push_back({shop, movie});
            if (++cnt == 5)
            {
                break;
            }
        }

        return ans;
    }
};