class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenExponent = false;
        bool seenDot = false;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if (isdigit(c)) {
                seenDigit = true;
            } 
            else if (c == '+' || c == '-') {
                // A sign can only appear at the very beginning or immediately after an exponent 'e' or 'E'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } 
            else if (c == 'e' || c == 'E') {
                // An exponent can only appear once and there must be a digit before it
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false; // Reset to ensure we have digits AFTER the exponent
            } 
            else if (c == '.') {
                // A decimal point can only appear once and CANNOT appear after an exponent
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } 
            else {
                // Any other character makes it an invalid number
                return false;
            }
        }
        
        // A valid number must end with a digit (e.g., "1e" is invalid, but "1e2" is valid)
        return seenDigit;
    }
};