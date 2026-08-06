#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // Target is in the left sorted half
                } else {
                    low = mid + 1;  // Target is in the right half
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // Target is in the right sorted half
                } else {
                    high = mid - 1; // Target is in the left half
                }
            }
        }

        return -1;
    }
};