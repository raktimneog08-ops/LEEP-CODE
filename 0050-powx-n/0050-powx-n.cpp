class Solution {
public:
    double myPow(double x, int n) {
        // Use long long to prevent overflow when n is -2^31
        long long power = n; 
        
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }
        
        double result = 1.0;
        while (power > 0) {
            // If the current power is odd, multiply the result by x
            if (power % 2 == 1) {
                result *= x;
            }
            // Square the base and halve the power for the next iteration
            x *= x;
            power /= 2;
        }
        
        return result;
    }
};