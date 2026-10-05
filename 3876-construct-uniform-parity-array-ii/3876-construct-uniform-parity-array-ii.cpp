#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    bool uniformArray(std::vector<int>& nums1) {
        int min_odd = INT_MAX;
        int min_even = INT_MAX;
        
        // Find the minimum odd and minimum even numbers in nums1
        for (int x : nums1) {
            if (x % 2 != 0) {
                min_odd = std::min(min_odd, x);
            } else {
                min_even = std::min(min_even, x);
            }
        }
        
        // Condition 1: All elements can be made even if there are no odd numbers.
        bool all_even = (min_odd == INT_MAX);
        
        // Condition 2: All elements can be made odd if there is at least one odd number,
        // and either there are no even numbers or the minimum even number is greater than min_odd.
        bool all_odd = (min_odd != INT_MAX) && (min_even == INT_MAX || min_even > min_odd);
        
        return all_even || all_odd;
    }
};