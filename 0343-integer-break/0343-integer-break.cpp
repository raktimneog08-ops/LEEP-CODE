class Solution {
public:
    int integerBreak(int n) {
        // Base cases where we are forced to break into smaller, suboptimal parts
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        int product = 1;
        
        // Keep extracting 3s as long as the remaining sum is greater than 4
        while (n > 4) {
            product *= 3;
            n -= 3;
        }
        
        // Multiply whatever is left (will be 2, 3, or 4)
        product *= n;
        
        return product;
    }
};