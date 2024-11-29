#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n)
    {
        int m = cells.size();
        for(int i = 0; i < n; i++)
        {
            vector<int> temp = cells;
            temp[0] = 0;
            temp[m - 1] = 0;

            for(int j = 1; j < m - 1; j++)
            {
                if(cells[j - 1] == cells[j + 1])
                {
                    temp[j] = 1;
                }
                else
                {
                    temp[j] = 0;
                }
            }
            cells = temp;
        }

        return cells;
    }
};