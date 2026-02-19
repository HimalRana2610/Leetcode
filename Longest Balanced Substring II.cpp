#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestBalanced(string s)
    {

        int ans = 0;
        auto pack = [](int x, int y) -> long long
        {
            return (static_cast<long long>(x) << 32) ^ (y & 0xffffffffLL);
        };

        auto touch = [&](unordered_map<long long, int> &mp, long long key, int idx)
        {
            auto it = mp.find(key);
            if (it != mp.end())
            {
                ans = max(ans, idx - it->second);
            }
            else
            {
                mp.emplace(key, idx);
            }
        };

        int pa = 0, pb = 0, pc = 0;
        unordered_map<long long, int> a, b, c, ab, ac, bc, abc;

        touch(a, pack(pb, pc), 0);
        touch(b, pack(pa, pc), 0);
        touch(c, pack(pa, pb), 0);
        touch(ab, pack(pa - pb, pc), 0);
        touch(ac, pack(pa - pc, pb), 0);
        touch(bc, pack(pb - pc, pa), 0);
        touch(abc, pack(pa - pb, pa - pc), 0);

        for (int i = 1; i <= s.length(); i++)
        {
            if (s[i - 1] == 'a')
            {
                pa++;
            }
            else if (s[i - 1] == 'b')
            {
                pb++;
            }
            else
            {
                pc++;
            }

            touch(a, pack(pb, pc), i);
            touch(b, pack(pa, pc), i);
            touch(c, pack(pa, pb), i);
            touch(ab, pack(pa - pb, pc), i);
            touch(ac, pack(pa - pc, pb), i);
            touch(bc, pack(pb - pc, pa), i);
            touch(abc, pack(pa - pb, pa - pc), i);
        }

        return ans;
    }
};