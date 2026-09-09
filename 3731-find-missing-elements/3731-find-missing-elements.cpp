#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findMissingElements(std::vector<int>& nums) {
        int min_val = nums[0];
        int max_val = nums[0];
        std::vector<bool> present(101, false);
        
        // Find min, max and mark present elements
        for (int num : nums) {
            min_val = std::min(min_val, num);
            max_val = std::max(max_val, num);
            present[num] = true;
        }
        
        std::vector<int> missing;
        
        // Collect all missing elements in the range (min_val, max_val)
        for (int i = min_val + 1; i < max_val; ++i) {
            if (!present[i]) {
                missing.push_back(i);
            }
        }
        
        return missing;
    }
};