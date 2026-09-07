class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        // end[i] stores the number of distinct subsequences ending with character i
        vector<long long> end(26, 0);
        long long total = 0; 
        
        for (char c : s) {
            int idx = c - 'a';
            
            long long prev_end = end[idx];
            
            // New subsequences ending with 'c' can be formed by appending 'c' 
            // to all existing distinct subsequences, plus the single character 'c' itself.
            end[idx] = (total + 1) % MOD;
            
            // The new total is the old total plus the new subsequences ending in 'c', 
            // minus the old subsequences ending in 'c' (to avoid double counting).
            total = (total + end[idx] - prev_end + MOD) % MOD;
        }
        
        return total;
    }
};