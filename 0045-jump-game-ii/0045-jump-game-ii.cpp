class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;
        
        // We only iterate up to nums.size() - 1 because we don't need to jump 
        // from the last element once we reach it.
        for (int i = 0; i < nums.size() - 1; i++) {
            // Update the farthest index we can reach from our current position
            farthest = max(farthest, i + nums[i]);
            
            // If we have reached the end of our current jump's range,
            // we must make another jump.
            if (i == current_end) {
                jumps++;
                current_end = farthest;
                
                // If our current end already reaches or exceeds the last index, we can stop
                if (current_end >= nums.size() - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};