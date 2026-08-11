class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        // Sort the array to bring duplicates next to each other
        sort(nums.begin(), nums.end());
        
        backtrack(nums, used, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if the current permutation is the same size as nums, we are done
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            // If the element is already used in the current permutation, skip it
            if (used[i]) continue;
            
            // Skip duplicates: 
            // If the current number is the same as the previous one, AND the previous one 
            // was NOT used in the current sequence, it means we are about to create a 
            // duplicate branch at this depth level.
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            
            // Choose the current element
            used[i] = true;
            current.push_back(nums[i]);
            
            // Explore further
            backtrack(nums, used, current, result);
            
            // Backtrack: remove the element and mark it as unused
            current.pop_back();
            used[i] = false;
        }
    }
};