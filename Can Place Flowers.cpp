#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        if(n == 0)
        {
            return true;
        }
        else if(flowerbed.size() == 1)
        {
            return flowerbed[0] == 0;
        }

        for(int i = 0; i < flowerbed.size(); i++)
        {
            if(flowerbed[i] == 0)
            {
                if(i == 0)
                {
                    if(flowerbed[i + 1] == 0)
                    {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else if(i == flowerbed.size() - 1)
                {
                    if(flowerbed[i - 1] == 0)
                    {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else
                {
                    if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                    {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
            }
            if(n == 0)
            {
                return true;
            }
        }
        return false;
    }
};