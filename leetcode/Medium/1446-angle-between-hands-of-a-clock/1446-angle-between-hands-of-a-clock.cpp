/*
 Problem: 1446. Angle Between Hands of a Clock
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 8.1 MB (42.82%)
 Tags: Math
*/
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes * 6.0;
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};