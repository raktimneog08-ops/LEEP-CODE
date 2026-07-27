#include <climits>

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        
        while (x != 0) {
            int pop = x % 10; // Extract the last digit
            x /= 10;          // Remove the last digit from x
            
            // Check for positive overflow before multiplying by 10 and adding pop
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) {
                return 0;
            }
            // Check for negative overflow before multiplying by 10 and adding pop
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) {
                return 0;
            }
            
            rev = rev * 10 + pop; // Push the digit to the reversed number
        }
        
        return rev;
    }
};