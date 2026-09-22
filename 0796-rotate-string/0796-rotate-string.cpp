#include <string>

class Solution {
public:
    bool rotateString(std::string s, std::string goal) {
        // A necessary condition for rotation is that both strings must be of equal length.
        if (s.length() != goal.length()) {
            return false;
        }
        
        // Concatenating 's' with itself creates a string that contains all 
        // possible valid shifts of 's' as contiguous substrings.
        std::string double_s = s + s;
        
        // Return true if 'goal' is found within 'double_s', otherwise false.
        // std::string::npos represents the highest possible value for an element of type size_t, 
        // returned by find() when a pattern is not found.
        return double_s.find(goal) != std::string::npos;
    }
};