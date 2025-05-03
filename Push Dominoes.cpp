#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.length(), index = -1;
        string ans(n, '.');

        char prev = '.';
        for(int i = 0; i < n; i++)
        {
            if(dominoes[i] != '.')
            {
                prev = dominoes[i];
                index = i;
                break;
            }
        }

        if(prev == '.')
        {
            return ans;
        }

        if(prev == 'L')
        {
            for(int i = 0; i <= index; i++)
            {
                ans[i] = 'L';
            }
        }

        for(int i = index + 1; i < n; i++)
        {
            if(dominoes[i] == 'L')
            {
                if(prev == 'R')
                {
                    int mid = (index + i) / 2;
                    if((index + i) % 2 != 0)
                    {
                        ans[mid] = 'R';
                    }

                    for(int j = index; j < mid; j++)
                    {
                        ans[j] = 'R';
                    }
                    for(int j = mid + 1; j <= i; j++)
                    {
                        ans[j] = 'L';
                    }
                }
                else
                {
                    for(int j = index; j <= i; j++)
                    {
                        ans[j] = 'L';
                    }
                }
                prev = 'L';
                index = i;
            }
            else if(dominoes[i] == 'R')
            {
                if(prev == 'R')
                {
                    for(int j = index; j <= i; j++)
                    {
                        ans[j] = 'R';
                    }
                }
                prev = 'R';
                index = i;
            }
        }

        if(prev == 'R')
        {
            for(int i = index; i < n; i++)
            {
                ans[i] = 'R';
            }
        }

        return ans;
    }
};