    #include <bits/stdc++.h>
    using namespace std;

    class Solution
    {
        public:
        bool canMakeZeroArray(vector<int> &nums, vector<vector<int>> &queries, int k)
        {
            vector<int> decrement(nums.size(), 0);

            for(int i = 0; i < k; i++)
            {
                int l = queries[i][0];
                int r = queries[i][1];
                int val = queries[i][2];

                decrement[l] += val;
                if(r + 1 < nums.size())
                {
                    decrement[r + 1] -= val;
                }
            }

            int currentDecrement = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                currentDecrement += decrement[i];
                if(nums[i] > currentDecrement)
                {
                    return false;
                }
            }

            return true;
        }

        int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
        {
            int left = 0, right = queries.size(), ans = -1;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(canMakeZeroArray(nums, queries, mid))
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