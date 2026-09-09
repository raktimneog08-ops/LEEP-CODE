#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingMultiple(std::vector<int>& nums, int k) {
        // Store all numbers in a hash set for O(1) lookups
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        int multiple = k;
        
        // Keep checking the next multiple of k until we find one not in the set
        while (numSet.count(multiple)) {
            multiple += k;
        }
        
        return multiple;
    }
};