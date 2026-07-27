#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLength = 1;
        
        // Helper lambda to expand around a given center and return the length of the palindrome
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Length is (right - 1) - (left + 1) + 1 = right - left - 1
            return right - left - 1;
        };
        
        for (int i = 0; i < s.length(); i++) {
            // Check for odd length palindromes (center is at character i)
            int len1 = expandAroundCenter(i, i);
            
            // Check for even length palindromes (center is between i and i+1)
            int len2 = expandAroundCenter(i, i + 1);
            
            int len = max(len1, len2);
            
            // If we found a longer palindrome, update the start index and maxLength
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLength);
    }
};