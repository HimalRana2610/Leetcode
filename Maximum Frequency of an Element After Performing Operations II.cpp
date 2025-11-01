#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> freq;
        set<int> m;

        int prev = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != nums[prev])
            {
                freq[nums[prev]] = i - prev;
                ans = max(ans, i - prev);
                m.insert(nums[prev]);

                if (nums[prev] - k >= nums[0])
                {
                    m.insert(nums[prev] - k);
                }
                if (nums[prev] + k <= nums.back())
                {
                    m.insert(nums[prev] + k);
                }

                prev = i;
            }
        }

        freq[nums[prev]] = nums.size() - prev;
        ans = max(ans, (int)nums.size() - prev);
        m.insert(nums[prev]);
        if (nums[prev] - k >= nums[0])
        {
            m.insert(nums[prev] - k);
        }
        if (nums[prev] + k <= nums.back())
        {
            m.insert(nums[prev] + k);
        }

        for (int x : m)
        {
            int left = 0, right = nums.size() - 1;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (nums[mid] < x - k)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }

            int l = left;
            left = 0, right = nums.size() - 1;

            while (left < right)
            {
                int mid = (left + right + 1) / 2;
                if (nums[mid] > x + k)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid;
                }
            }

            int r = left, current;
            if (freq.count(x))
            {
                current = min(r - l + 1, freq[x] + numOperations);
            }
            else
            {
                current = min(r - l + 1, numOperations);
            }
            ans = max(ans, current);
        }

        return ans;
    }
};