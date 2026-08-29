class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        
        // Traverse from right to left to find where the strictly increasing order breaks
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] >= nums[i + 1]) {
                // The prefix up to index i must be removed
                return i + 1;
            }
        }
        
        // The array is already strictly increasing
        return 0;
    }
};