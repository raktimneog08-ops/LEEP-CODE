#include <vector>

class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] stores whether the first player to move wins with i stones left
        std::vector<bool> dp(n + 1, false);
        
        // Build the DP table from 1 up to n
        for (int i = 1; i <= n; ++i) {
            // Try removing all possible non-zero square numbers less than or equal to i
            for (int k = 1; k * k <= i; ++k) {
                // If we can force the opponent into a losing state (false),
                // then the current state is a winning state (true).
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // We found a winning strategy, no need to check other moves
                }
            }
        }
        
        // Return the result for n stones
        return dp[n];
    }
};