#include <bits/stdc++.h>
using namespace std;

class FoodRatings
{
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, set<pair<int, string>>> cuisineHeap;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            foodRating[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            cuisineHeap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        string c = foodCuisine[food];
        int oldRating = foodRating[food];

        cuisineHeap[c].erase({-oldRating, food});
        foodRating[food] = newRating;
        cuisineHeap[c].insert({-newRating, food});
    }

    string highestRated(string cuisine)
    {
        return cuisineHeap[cuisine].begin()->second;
    }
};