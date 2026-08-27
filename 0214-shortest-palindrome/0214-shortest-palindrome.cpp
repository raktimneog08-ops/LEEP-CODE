#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string shortestPalindrome(std::string s) {
        if (s.empty()) return s;

        std::string rev = s;
        std::reverse(rev.begin(), rev.end());

        // Create temporary string with a separator
        std::string combined = s + "#" + rev;
        int n = combined.length();

        // Compute KMP prefix table (pi array)
        std::vector<int> pi(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = pi[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            pi[i] = j;
        }

        // Longest palindromic prefix length
        int longestPalPrefix = pi[n - 1];

        // Suffix not included in the palindromic prefix
        std::string nonPalSuffix = s.substr(longestPalPrefix);
        std::reverse(nonPalSuffix.begin(), nonPalSuffix.end());

        return nonPalSuffix + s;
    }
};