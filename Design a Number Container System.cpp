#include<bits/stdc++.h>
using namespace std;

class NumberContainers
{
    unordered_map<int, int> number_at;
    unordered_map<int, set<int>> index_of;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> min_indices;

    public:
    NumberContainers()
    {
        number_at.clear();
        index_of.clear();
    }

    void change(int index, int number)
    {
        if(number_at.find(index) != number_at.end())
        {
            int old_number = number_at[index];
            index_of[old_number].erase(index);
        }

        number_at[index] = number;
        index_of[number].insert(index);

        min_indices[number].push(index);
    }

    int find(int number)
    {
        if(index_of.find(number) == index_of.end() || index_of[number].empty())
        {
            return -1;
        }

        while(!min_indices[number].empty())
        {
            int top_index = min_indices[number].top();
            if(index_of[number].count(top_index))
            {
                return top_index;
            }
            else
            {
                min_indices[number].pop();
            }
        }

        return -1;
    }
};