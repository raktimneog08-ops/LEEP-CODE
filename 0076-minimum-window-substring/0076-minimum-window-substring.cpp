#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Array to keep track of the frequency of characters in t
        vector<int> charCount(128, 0);
        for (char c : t) {
            charCount[c]++;
        }

        int requiredChars = t.length(); 
        int left = 0, right = 0;        
        int minLen = s.length() + 1;    
        int minStart = 0;               

        while (right < s.length()) {
            // Include the current character in the window
            char rightChar = s[right];
            if (charCount[rightChar] > 0) {
                requiredChars--;
            }
            charCount[rightChar]--;
            right++;

            // When all required characters are in the current window, try to shrink it
            while (requiredChars == 0) {
                // Update the minimum window if the current one is smaller
                if (right - left < minLen) {
                    minLen = right - left;
                    minStart = left;
                }

                // Remove the leftmost character from the window
                char leftChar = s[left];
                charCount[leftChar]++;
                if (charCount[leftChar] > 0) {
                    requiredChars++;
                }
                left++;
            }
        }

        return minLen > s.length() ? "" : s.substr(minStart, minLen);
    }
};