class Solution {
    int dp[501][501];
    int prefix[502];

    int solve(int i, int j) {
        // Base case: only one stone left, no score can be gained
        if (i == j) return 0;
        
        // Return cached result if already computed
        if (dp[i][j] != -1) return dp[i][j];

        int maxScore = 0;
        
        // Try all possible splits for the current subarray
        for (int k = i; k < j; ++k) {
            int leftSum = prefix[k + 1] - prefix[i];
            int rightSum = prefix[j + 1] - prefix[k + 1];

            if (leftSum < rightSum) {
                maxScore = max(maxScore, leftSum + solve(i, k));
            } else if (leftSum > rightSum) {
                maxScore = max(maxScore, rightSum + solve(k + 1, j));
            } else {
                // If equal, Alice can choose either the left or right part optimally
                maxScore = max(maxScore, leftSum + max(solve(i, k), solve(k + 1, j)));
            }
        }
        
        return dp[i][j] = maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // Build prefix sums for O(1) subarray sum queries
        prefix[0] = 0;
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        
        // Initialize DP table with -1
        memset(dp, -1, sizeof(dp));
        
        return solve(0, n - 1);
    }
};