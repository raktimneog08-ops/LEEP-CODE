class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0; // Largest digit
        int max2 = 0; // Second largest digit
        
        while (n > 0) {
            int digit = n % 10; // Extract the last digit
            
            if (digit > max1) {
                max2 = max1;    // The old max becomes the second max
                max1 = digit;   // Update the new max
            } else if (digit > max2) {
                max2 = digit;   // Update the second max only
            }
            
            n /= 10; // Remove the last digit
        }
        
        return max1 * max2;
    }
};