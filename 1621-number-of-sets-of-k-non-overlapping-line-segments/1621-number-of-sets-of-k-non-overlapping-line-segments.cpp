class Solution {
    int memo[1001][1001][2];
    int MOD = 1e9 + 7;

    int dp(int i, int k, bool isStart, int n) {
        // Base cases
        if (k == 0) return 1; // Successfully placed all k segments
        if (i == n) return 0; // Ran out of points before placing all segments
        
        // Return cached result if already computed
        if (memo[i][k][isStart] != -1) return memo[i][k][isStart];

        // Option 1: Skip the current point
        long long ans = dp(i + 1, k, isStart, n); 

        // Option 2: Take the current point
        if (isStart) {
            // Start a new segment here. We move to the next point (i+1) looking for an endpoint.
            ans = (ans + dp(i + 1, k, false, n)) % MOD;
        } else {
            // End the current segment here. We successfully placed 1 segment (k-1).
            // We pass 'i' (not i+1) because the next segment can start at this exact same point.
            ans = (ans + dp(i, k - 1, true, n)) % MOD;
        }

        return memo[i][k][isStart] = ans;
    }

public:
    int numberOfSets(int n, int k) {
        memset(memo, -1, sizeof(memo));
        // Start at point 0, with k segments to place, looking for a start point (isStart = true)
        return dp(0, k, true, n); 
    }
};