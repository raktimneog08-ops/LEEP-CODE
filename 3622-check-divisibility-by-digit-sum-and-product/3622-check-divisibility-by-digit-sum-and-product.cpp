class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int digitSum = 0;
        int digitProduct = 1;
        
        // Extract digits one by one
        while (temp > 0) {
            int digit = temp % 10;
            digitSum += digit;
            digitProduct *= digit;
            temp /= 10;
        }
        
        // Check if n is divisible by the sum of digitSum and digitProduct
        int total = digitSum + digitProduct;
        return (n % total) == 0;
    }
};