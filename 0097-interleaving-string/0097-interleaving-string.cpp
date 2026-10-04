#include <string>
#include <vector>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        
        // The length of s3 must equal the sum of s1 and s2 lengths
        if (n1 + n2 != n3) {
            return false;
        }
        
        // 1D DP array to optimize space to O(s2.length())
        std::vector<bool> dp(n2 + 1, false);
        dp[0] = true;
        
        // Initialize the base case when s1 is empty (only s2 contributes)
        for (int j = 1; j <= n2; ++j) {
            dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
        }
        
        // Iteratively build up using characters from s1 and s2
        for (int i = 1; i <= n1; ++i) {
            dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= n2; ++j) {
                bool from_top = dp[j] && (s1[i - 1] == s3[i + j - 1]);
                bool from_left = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
                dp[j] = from_top || from_left;
            }
        }
        
        return dp[n2];
    }
};