#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        // Step 1: Sort the array
        std::sort(nums.begin(), nums.end());

        // Step 2: Fix the first element
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Fix the second element
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicate values for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Step 4: Use Two Pointers for the remaining two elements
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for the third element
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Skip duplicates for the fourth element
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    } else if (sum < target) {
                        left++; // Need a larger sum
                    } else {
                        right--; // Need a smaller sum
                    }
                }
            }
        }

        return result;
    }
};