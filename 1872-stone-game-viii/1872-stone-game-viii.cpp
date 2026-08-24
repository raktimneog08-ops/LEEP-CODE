#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        
        // Compute prefix sums in-place
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        
        // Base case: dp[n - 1] = pref[n - 1]
        int max_diff = stones[n - 1];
        
        // Transition backwards from n - 2 down to 1
        for (int i = n - 2; i >= 1; --i) {
            max_diff = std::max(max_diff, stones[i] - max_diff);
        }
        
        return max_diff;
    }
};