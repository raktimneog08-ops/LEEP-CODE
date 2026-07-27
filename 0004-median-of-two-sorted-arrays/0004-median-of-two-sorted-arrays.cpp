#include <vector>
#include <algorithm>
#include <climits>
#include <stdexcept>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array to optimize the binary search space
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        int totalLeft = (m + n + 1) / 2; // Number of elements in the left partition

        while (low <= high) {
            int partitionX = low + (high - low) / 2;
            int partitionY = totalLeft - partitionX;

            // Handle edge cases where the partition is at the extreme ends
            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];

            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            // Check if we have found the correct partition
            if (maxX <= minY && maxY <= minX) {
                // If the total number of elements is even
                if ((m + n) % 2 == 0) {
                    return (max(maxX, maxY) + min(minX, minY)) / 2.0;
                } 
                // If the total number of elements is odd
                else {
                    return max(maxX, maxY);
                }
            } 
            // We are too far on the right side for partitionX, move left
            else if (maxX > minY) {
                high = partitionX - 1;
            } 
            // We are too far on the left side for partitionX, move right
            else {
                low = partitionX + 1;
            }
        }

        // Execution should not reach here if inputs are valid and sorted
        throw invalid_argument("Input arrays are not sorted or are invalid.");
    }
};