#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        unordered_set<string> s(supplies.begin(), supplies.end());
        unordered_map<string, int> visited;
        vector<string> ans;

        unordered_map<string, vector<string>> ingred;
        for(int i = 0; i < recipes.size(); i++)
        {
            ingred[recipes[i]] = ingredients[i];
        }

        function<bool(string)> can_make = [&](string str)
        {
            if(visited.count(str))
            {
                return visited[str] == 1;
            }
            if(s.count(str))
            {
                return true;
            }
            if(!ingred.count(str))
            {
                return false;
            }

            visited[str] = 0;
            for(int i = 0; i < ingred[str].size(); i++)
            {
                if(!can_make(ingred[str][i]))
                {
                    visited[str] = -1;
                    return false;
                }
            }

            visited[str] = 1;
            ans.push_back(str);
            return true;
        };

        for(int i = 0; i < recipes.size(); i++)
        {
            can_make(recipes[i]);
        }

        return ans;
    }
};