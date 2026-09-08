#include <cmath>
#include <algorithm>

class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Calculate the angle of the minute hand from 12:00
        double minute_angle = minutes * 6.0;
        
        // Calculate the angle of the hour hand from 12:00
        double hour_angle = (hour % 12) * 30.0 + (minutes * 0.5);
        
        // Find the absolute difference between the two angles
        double diff = std::abs(hour_angle - minute_angle);
        
        // Return the smaller angle
        return std::min(diff, 360.0 - diff);
    }
};
