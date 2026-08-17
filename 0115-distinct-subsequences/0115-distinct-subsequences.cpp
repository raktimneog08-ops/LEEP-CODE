#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // Use unsigned long long to prevent integer overflow during intermediate calculations.
        // The problem guarantees the *final* answer fits in a 32-bit integer.
        vector<unsigned long long> dp(n + 1, 0);
        
        // Base case: empty t can be formed exactly 1 way
        dp[0] = 1;
        
        for (int i = 1; i <= m; i++) {
            // Iterate backwards to safely overwrite values in place
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
                // If s[i-1] != t[j-1], dp[j] remains unchanged (dp[j] = dp[j])
            }
        }
        
        return dp[n];
    }
};