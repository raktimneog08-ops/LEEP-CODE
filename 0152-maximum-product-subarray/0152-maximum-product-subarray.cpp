class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Initialize the max, min, and the global result with the first element
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            int curr = nums[i];
            
            // Calculate the potential new max and min products
            // We use a temporary variable for max_so_far because we need the old value to calculate the new min_so_far
            int temp_max = max(curr, max(max_so_far * curr, min_so_far * curr));
            min_so_far = min(curr, min(max_so_far * curr, min_so_far * curr));
            
            max_so_far = temp_max;
            
            // Update the global maximum product found so far
            result = max(result, max_so_far);
        }
        
        return result;
    }
};