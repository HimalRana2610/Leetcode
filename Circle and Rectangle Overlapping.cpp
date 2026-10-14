#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        int dx = xCenter - max(x1, min(xCenter, x2)), dy = yCenter - max(y1, min(yCenter, y2));
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};