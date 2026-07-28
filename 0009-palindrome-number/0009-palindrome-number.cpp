class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes.
        // Also, if the last digit of the number is 0, the first digit must also be 0.
        // Only 0 satisfies this property.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        
        // We only need to reverse half of the digits to avoid overflow.
        // We know we've reached the middle when x is less than or equal to the revertedNumber.
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by revertedNumber / 10.
        // For example, when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123.
        return x == revertedNumber || x == revertedNumber / 10;
    }
};