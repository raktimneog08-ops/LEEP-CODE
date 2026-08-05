class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special overflow case: -2^31 / -1 = 2^31 (exceeds INT_MAX)
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine if the result will be negative
        bool negative = (dividend > 0) ^ (divisor > 0);

        // Convert both numbers to negative to safely handle INT_MIN
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;

        int quotient = 0; // Stored as a negative accumulator

        // Perform bitwise division
        while (dividend <= divisor) {
            int temp_divisor = divisor;
            int count = -1; // Keep count negative to avoid overflow

            // Double the divisor until shifting further would exceed dividend
            while (temp_divisor >= (INT_MIN >> 1) && dividend <= (temp_divisor << 1)) {
                temp_divisor <<= 1;
                count <<= 1;
            }

            dividend -= temp_divisor;
            quotient += count; // Accumulate negative steps
        }

        // If the result should be positive, negate the negative quotient
        return negative ? quotient : -quotient;
    }
};