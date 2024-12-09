#include<bits/stdc++.h>
using namespace std;

struct Phash
{
    size_t operator()(const pair<int, int>& point) const
    {
        return hash<int>()(point.first) ^ hash<int>()(point.second);
    }
};

class Solution
{
    public:
    int maxRectangleArea(vector<vector<int>>& points)
    {
        unordered_set<pair<int, int>, Phash> p;
        for(int i = 0; i < points.size(); i++)
        {
            p.insert({points[i][0], points[i][1]});
        }

        int ans = -1;
        for(int i = 0; i < points.size(); i++)
        {
            for(int j = i + 1; j < points.size(); j++)
            {
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                if(x1 != x2 && y1 != y2)
                {
                    if(p.count({x1, y2}) && p.count({x2, y1}))
                    {
                        bool flag = true;
                        for(int k = 0; k < points.size(); k++)
                        {
                            int x = points[k][0], y = points[k][1];
                            if((x1 < x && x < x2 || x2 < x && x < x1) && (y1 < y && y < y2 || y2 < y && y < y1))
                            {
                                flag = false;
                                break;
                            }

                            if((x == x1 || x == x2) && ((y1 <= y && y <= y2) || (y2 <= y && y <= y1)))
                            {
                                if(make_pair(x, y) != make_pair(x1, y1) && make_pair(x, y) != make_pair(x1, y2) && make_pair(x, y) != make_pair(x2, y1) && make_pair(x, y) != make_pair(x2, y2))
                                {
                                    flag = false;
                                    break;
                                }
                            }

                            if((y == y1 || y == y2) && ((x1 <= x && x <= x2) || (x2 <= x && x <= x1)))
                            {
                                if(make_pair(x, y) != make_pair(x1, y1) && make_pair(x, y) != make_pair(x1, y2) && make_pair(x, y) != make_pair(x2, y1) && make_pair(x, y) != make_pair(x2, y2))
                                {
                                    flag = false;
                                    break;
                                }
                            }
                        }

                        if(flag)
                        {
                            int area = abs(x2 - x1) * abs(y2 - y1);
                            ans = max(ans, area);
                        }
                    }
                }
            }
        }

        return ans;
    }
};