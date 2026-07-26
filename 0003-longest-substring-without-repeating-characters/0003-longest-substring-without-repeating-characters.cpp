#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Array to store the last seen index of each character. 
        // Size 128 covers all standard ASCII characters.
        vector<int> charIndex(128, -1);
        
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // If the character was seen before and is within the current window,
            // move the left pointer to the right of its last occurrence.
            if (charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            
            // Update the last seen index of the current character
            charIndex[s[right]] = right;
            
            // Calculate the current window size and update the maximum length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};