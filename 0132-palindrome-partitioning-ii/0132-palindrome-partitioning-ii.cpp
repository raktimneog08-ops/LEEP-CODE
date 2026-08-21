#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) return 0;

        // isPal[i][j] will be true if substring s[i...j] is a palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        
        // dp[i] stores the minimum cuts needed for prefix s[0...i]
        vector<int> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            int minCuts = i; // Maximum cuts needed is i (cut every character)

            for (int j = 0; j <= i; ++j) {
                // Check if substring s[j...i] is a palindrome
                if (s[j] == s[i] && (i - j <= 2 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;
                    
                    // If the entire prefix s[0...i] is a palindrome, 0 cuts needed
                    if (j == 0) {
                        minCuts = 0;
                    } else {
                        minCuts = min(minCuts, dp[j - 1] + 1);
                    }
                }
            }
            dp[i] = minCuts;
        }

        return dp[n - 1];
    }
};