class Solution {
public:
    int numTrees(int n) {
        // dp[i] stores the number of unique BSTs that can be formed with i nodes
        vector<int> dp(n + 1, 0);
        
        // Base cases: 
        // 0 nodes = 1 way (empty tree)
        // 1 node = 1 way (single root)
        dp[0] = 1;
        dp[1] = 1;
        
        // Build up the solutions for 2 to n nodes
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                // If j is the root, there are (j-1) nodes in the left subtree 
                // and (i-j) nodes in the right subtree.
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        
        return dp[n];
    }
};