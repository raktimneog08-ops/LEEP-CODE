class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Precompute the minimum values from the right (suffix minimums)
        vector<int> suffMin(n);
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }
        
        int currentMax = -1; 
        
        // Iterate to find the prefix max dynamically and check the condition
        for (int i = 0; i < n; i++) {
            currentMax = max(currentMax, nums[i]);
            
            // Instability score: max(nums[0..i]) - min(nums[i..n-1])
            if (currentMax - suffMin[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};