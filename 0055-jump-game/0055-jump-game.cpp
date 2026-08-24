#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int max_reach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // Cannot reach the current index
            if (i > max_reach) {
                return false;
            }
            
            max_reach = std::max(max_reach, i + nums[i]);
            
            // Early exit if the end is reachable
            if (max_reach >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};