class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Step 1: Calculate the sum of the longest sequential prefix
        int prefix_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                prefix_sum += nums[i];
            } else {
                break; // Stop at the first non-sequential element
            }
        }
        
        // Step 2: Store all array elements in a hash set for O(1) lookups
        unordered_set<int> num_set(nums.begin(), nums.end());
        
        // Step 3: Find the smallest missing integer >= prefix_sum
        int x = prefix_sum;
        while (num_set.count(x)) {
            x++;
        }
        
        return x;
    }
};