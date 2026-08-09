class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if target is achieved, add the current combination to the result
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates to avoid duplicate combinations in the result
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            // Pruning: if the current number is greater than the target, 
            // no need to continue since the array is sorted
            if (candidates[i] > target) {
                break; 
            }
            
            // Include the current number
            current.push_back(candidates[i]);
            
            // Recurse with the reduced target. 
            // We pass 'i + 1' as the start index because each number can only be used once.
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            
            // Backtrack: remove the last added number to explore other combinations
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sorting is crucial for handling duplicates and optimizing with pruning
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, current, result);
        
        return result;
    }
};