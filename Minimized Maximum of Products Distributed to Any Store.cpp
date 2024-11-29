#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool can_distribute(int n, vector<int> &quantities, int max_products)
    {
        int stores = 0;
        for(int i = 0; i < quantities.size(); i++)
        {
            stores += quantities[i] / max_products;
            if(quantities[i] % max_products != 0)
            {
                stores++;
            }
            if(stores > n)
            {
                return false;
            }
        }
        return stores <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities)
    {
        int left = 1, right = *max_element(quantities.begin(), quantities.end()), ans = -1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(can_distribute(n, quantities, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};