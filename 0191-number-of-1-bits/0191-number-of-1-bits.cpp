class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        // Brian Kernighan's Algorithm: Clears the lowest set bit in each iteration
        while (n > 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};