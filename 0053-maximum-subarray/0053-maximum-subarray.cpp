#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        // Initialize with the first element
        int max_sum = nums[0];
        int current_sum = nums[0];
        
        // Iterate starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // Decide whether to add the current element to the existing subarray 
            // or start a new subarray from the current element.
            current_sum = std::max(nums[i], current_sum + nums[i]);
            
            // Update the global maximum sum if the current contiguous sum is strictly greater
            max_sum = std::max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};