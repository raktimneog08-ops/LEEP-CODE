#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Stores the value as the key and its index as the value
        std::unordered_map<int, int> num_to_index;
        
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the required value to reach the target
            int complement = target - nums[i];
            
            // Check if the complement exists in our map
            if (num_to_index.find(complement) != num_to_index.end()) {
                return {num_to_index[complement], i};
            }
            
            // If not found, store the current number and its index
            num_to_index[nums[i]] = i;
        }
        
        return {}; // Return empty vector if no solution is found
    }
};