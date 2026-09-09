class Solution {
public:
    // Helper function to calculate the product of digits
    int getDigitProduct(int num) {
        int product = 1;
        while (num > 0) {
            product *= (num % 10);
            num /= 10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        int current = n;
        
        // Brute-force check starting from n
        while (true) {
            if (getDigitProduct(current) % t == 0) {
                return current;
            }
            current++;
        }
    }
};