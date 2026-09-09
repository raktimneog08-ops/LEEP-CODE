class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long threshold = 1000;
        
        // Loop through powers of 1000 (1,000, 1,000,000, etc.)
        while (n >= threshold) {
            totalCommas += (n - threshold + 1);
            threshold *= 1000;
        }
        
        return totalCommas;
    }
};