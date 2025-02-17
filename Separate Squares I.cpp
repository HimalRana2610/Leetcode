#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    double separateSquares(vector<vector<int>>& squares)
    {
        int n = squares.size();
        double total_area = 0.0;

        for(int i = 0; i < n; i++)
        {
            total_area += static_cast<double>(squares[i][2]) * squares[i][2];
        }

        double target = total_area / 2;
        int l = INT_MAX, h = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            l = min(l, squares[i][1]);
            h = max(h, squares[i][1] + squares[i][2]);
        }

        double low = static_cast<double>(l), high = static_cast<double>(h);
        for(int i = 0; i < 100; i++)
        {
            double mid = (low + high) / 2.0, current_area = 0.0;
            for(int j = 0; j < n; j++)
            {
                if(mid <= squares[j][1])
                {
                    current_area += static_cast<double>(squares[j][2]) * squares[j][2];
                }
                else if(mid < squares[j][1] + squares[j][2])
                {
                    current_area += static_cast<double>(squares[j][2]) * (squares[j][1] + squares[j][2] - mid);
                }
            }

            if(current_area > target)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }

        return (low + high) / 2.0;
    }
};