#include <bits/stdc++.h>
using namespace std;

class matrix
{
    public:
    vector<vector<int>> arr;

    matrix() : arr(26, vector<int>(26, 0)) {}

    static matrix identity()
    {
        matrix I;
        for(int i = 0; i < 26; i++)
        {
            I.arr[i][i] = 1;
        }
        return I;
    }

    matrix operator*(const matrix &o) const
    {
        matrix R;
        for(int i = 0; i < 26; i++)
        {
            for(int k = 0; k < 26; k++)
                if(arr[i][k])
                {
                    long long aik = arr[i][k];
                    for(int j = 0; j < 26; j++)
                    {
                        R.arr[i][j] = (R.arr[i][j] + aik * o.arr[k][j]) % 1000000007;
                    }
                }
        }
        return R;
    }
};

matrix matPow(matrix base, long long exp)
{
    matrix res = matrix::identity();
    while(exp > 0)
    {
        if(exp & 1)
        {
            res = res * base;
        }
        base = base * base;
        exp >>= 1;
    }
    return res;
}

class Solution
{
    public:
    int lengthAfterTransformations(string s, long long t, vector<int> &nums)
    {
        vector<int> freq(26, 0);
        for(char c : s)
        {
            freq[c - 'a']++;
        }

        matrix mat;
        for(int a = 0; a < 26; a++)
        {
            for(int k = 0; k < nums[a]; k++)
            {
                int b = (a + k + 1) % 26;
                mat.arr[b][a] = (mat.arr[b][a] + 1) % 1000000007;
            }
        }

        matrix Mt = matPow(mat, t);

        long long ans = 0;
        for(int b = 0; b < 26; b++)
        {
            long long sum = 0;
            for(int a = 0; a < 26; a++)
            {
                sum = (sum + (long long)Mt.arr[b][a] * freq[a]) % 1000000007;
            }
            ans = (ans + sum) % 1000000007;
        }
        return ans;
    }
};