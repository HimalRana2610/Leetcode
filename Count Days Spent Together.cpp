#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculateDayOfYear(const string &day, const vector<int> &prefix)
    {
        return prefix[stoi(day.substr(0, 2)) - 1] + stoi(day.substr(3));
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, prefix(1, 0);
        for (int i = 0; i < days.size(); i++)
        {
            prefix.emplace_back(prefix.back() + days[i]);
        }

        return max(0, min(calculateDayOfYear(leaveAlice, prefix), calculateDayOfYear(leaveBob, prefix)) - max(calculateDayOfYear(arriveAlice, prefix), calculateDayOfYear(arriveBob, prefix)) + 1);
    }
};