class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;
        
        // Arrays to store prefix maximums and suffix minimums
        vector<int> prefMax(n);
        vector<int> suffMin(n);
        
        // 1. Build Prefix Max array
        prefMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }
        
        // 2. Build Suffix Min array
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }
        
        // 3. Find the smallest stable index
        for (int i = 0; i < n; ++i) {
            int instability_score = prefMax[i] - suffMin[i];
            if (instability_score <= k) {
                return i;
            }
        }
        
        // If no stable index is found
        return -1;
    }
};