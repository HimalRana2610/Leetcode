#include<bits/stdc++.h>
using namespace std;

class ProductOfNumbers
{
    vector<int> arr;
    public:
    ProductOfNumbers()
    {
        arr.clear();
    }

    void add(int num)
    {
        arr.push_back(num);
    }

    int getProduct(int k)
    {
        int ans = 1;
        for(int i = arr.size() - 1; k > 0; i--, k--)
        {
            ans *= arr[i];
        }

        return ans;
    }
};