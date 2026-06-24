#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double minute_angle = minutes * 6;
        hour %= 12;
        double hours = hour + (minutes / 60.0);
        double hour_angle = hours * 30;
        double angle = abs(hour_angle - minute_angle);
        return min(angle, 360 - angle);
    }
};