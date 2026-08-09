class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if target is achieved, add the current combination to the result
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // If the target becomes negative, this combination is invalid
        if (target < 0) {
            return;
        }
        
        // Iterate through the candidates starting from the 'start' index
        for (int i = start; i < candidates.size(); ++i) {
            // Include the current number
            current.push_back(candidates[i]);
            
            // Recurse with the reduced target. 
            // Notice we pass 'i' as the start index to allow unlimited reuse of the same number.
            backtrack(candidates, target - candidates[i], i, current, result);
            
            // Backtrack: remove the last added number to explore other combinations
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        backtrack(candidates, target, 0, current, result);
        
        return result;
    }
};