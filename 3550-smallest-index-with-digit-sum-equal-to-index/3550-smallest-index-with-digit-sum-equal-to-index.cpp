#include <vector>

class Solution {
public:
    int smallestIndex(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int temp = nums[i];
            int digitSum = 0;
            
            // Handle numbers greater than 0 to compute digit sum
            if (temp == 0) {
                digitSum = 0;
            } else {
                while (temp > 0) {
                    digitSum += temp % 10;
                    temp /= 10;
                }
            }
            
            // Check if the digit sum equals the current index
            if (digitSum == i) {
                return i;
            }
        }
        
        // Return -1 if no such index exists
        return -1;
    }
};