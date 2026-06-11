#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n - 1, row = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target < matrix[mid][0])
            {
                right = mid - 1;
            }
            else if (target > matrix[mid][m - 1])
            {
                left = mid + 1;
            }
            else
            {
                row = mid;
                break;
            }
        }

        if (row == -1)
        {
            return false;
        }

        left = 0;
        right = m - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target < matrix[row][mid])
            {
                right = mid - 1;
            }
            else if (target > matrix[row][mid])
            {
                left = mid + 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};