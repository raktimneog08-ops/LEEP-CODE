
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Minimum is in the right half
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                // Minimum is at mid or in the left half
                right = mid;
            } else {
                // nums[mid] == nums[right]: Cannot determine half, decrement right
                right--;
            }
        }

        return nums[left];
    }
};