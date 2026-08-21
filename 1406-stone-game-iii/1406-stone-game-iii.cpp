#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::string stoneGameIII(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        // dp[i] stores the maximum score difference the current player 
        // can achieve starting from index i.
        std::vector<int> dp(n + 1, 0); 
        
        // Traverse backwards from the last stone
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = INT_MIN;
            int current_take = 0;
            
            // The player can take 1, 2, or 3 stones
            for (int k = 1; k <= 3 && i + k - 1 < n; ++k) {
                current_take += stoneValue[i + k - 1];
                dp[i] = std::max(dp[i], current_take - dp[i + k]);
            }
        }
        
        // dp[0] represents Alice's score minus Bob's score
        if (dp[0] > 0) {
            return "Alice";
        } else if (dp[0] < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};