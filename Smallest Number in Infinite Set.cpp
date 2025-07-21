#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet
{
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> s;

public:
    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
        {
            pq.push(i);
            s.insert(i);
        }
    }

    int popSmallest()
    {
        int ans = pq.top();
        pq.pop();
        s.erase(ans);

        return ans;
    }

    void addBack(int num)
    {
        if (s.find(num) == s.end())
        {
            s.insert(num);
            pq.push(num);
        }
    }
};