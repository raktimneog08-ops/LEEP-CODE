class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // best[i] stores the minimum length of a valid sub-array found in arr[0...i]
        vector<int> best(n, 1e9); 
        
        int sum = 0;
        int left = 0;
        int ans = 1e9;
        int min_len = 1e9; // Tracks the minimum length of a valid sub-array seen so far
        
        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            
            // Shrink the window if the sum exceeds the target
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }
            
            // If we find a valid sub-array
            if (sum == target) {
                int current_len = right - left + 1;
                
                // If there is a valid non-overlapping sub-array before the current window's left pointer
                if (left > 0 && best[left - 1] != 1e9) {
                    ans = min(ans, current_len + best[left - 1]);
                }
                
                // Update the overall minimum length seen so far
                min_len = min(min_len, current_len);
            }
            
            // Record the minimum length found up to the current right index
            best[right] = min_len;
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};