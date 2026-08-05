#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool can_win(vector<int> &nums, int l, int r, int first, int second, bool turn)
    {
        if (l == r)
        {
            if (turn)
            {
                first += nums[l];
            }
            else
            {
                second += nums[l];
            }

            return first >= second;
        }

        if (turn)
        {
            return can_win(nums, l + 1, r, first + nums[l], second, !turn) || can_win(nums, l, r - 1, first + nums[r], second, !turn);
        }

        return can_win(nums, l + 1, r, first, second + nums[l], !turn) && can_win(nums, l, r - 1, first, second + nums[r], !turn);
    }

    bool predictTheWinner(vector<int> &nums)
    {
        return can_win(nums, 0, nums.size() - 1, 0, 0, true);
    }
};