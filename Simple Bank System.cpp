#include <bits/stdc++.h>
using namespace std;

class Bank
{
    int n;
    vector<long long> accounts;

public:
    Bank(vector<long long> &balance)
    {
        n = balance.size();
        accounts.push_back(0);

        for (int i = 0; i < n; i++)
        {
            accounts.push_back(balance[i]);
        }
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (account1 > n || account2 > n || accounts[account1] < money)
        {
            return false;
        }

        accounts[account1] -= money;
        accounts[account2] += money;

        return true;
    }

    bool deposit(int account, long long money)
    {
        if (account > n)
        {
            return false;
        }

        accounts[account] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (account > n || accounts[account] < money)
        {
            return false;
        }

        accounts[account] -= money;
        return true;
    }
};