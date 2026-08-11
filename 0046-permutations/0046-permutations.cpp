class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        // Base case: if the starting index reaches the end of the array,
        // we've formed a complete permutation.
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        // Explore all possible choices for the current position
        for (int i = start; i < nums.size(); ++i) {
            // Swap to place the element at the current 'start' position
            swap(nums[start], nums[i]);
            
            // Recurse to generate permutations for the remaining positions
            backtrack(nums, start + 1, result);
            
            // Backtrack: swap back to restore the original array state
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};