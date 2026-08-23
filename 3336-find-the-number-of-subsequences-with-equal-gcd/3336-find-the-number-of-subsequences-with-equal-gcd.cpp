#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int subsequencePairCount(std::vector<int>& nums) {
        int max_val = *std::max_element(nums.begin(), nums.end());
        int MOD = 1e9 + 7;

        // dp[g1][g2] stores the number of valid pairs of subsequences
        // with GCDs g1 and g2. 0 represents an empty subsequence.
        std::vector<std::vector<int>> dp(max_val + 1, std::vector<int>(max_val + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            std::vector<std::vector<int>> next_dp = dp;

            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] == 0) continue;

                    // Option 1: Add x to seq1
                    int new_g1 = (g1 == 0) ? x : std::gcd(g1, x);
                    next_dp[new_g1][g2] = (next_dp[new_g1][g2] + dp[g1][g2]) % MOD;

                    // Option 2: Add x to seq2
                    int new_g2 = (g2 == 0) ? x : std::gcd(g2, x);
                    next_dp[g1][new_g2] = (next_dp[g1][new_g2] + dp[g1][g2]) % MOD;
                }
            }
            dp = std::move(next_dp);
        }

        // Sum configurations where both seq1 and seq2 are non-empty (g > 0) and g1 == g2
        long long ans = 0;
        for (int g = 1; g <= max_val; ++g) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};