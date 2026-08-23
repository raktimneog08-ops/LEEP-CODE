#include <vector>
#include <string>

class Solution {
public:
    std::string findTheString(std::vector<std::vector<int>>& lcp) {
        int n = lcp.size();
        std::string s(n, 0);
        char current_char = 'a';

        // Step 1: Greedily construct the string
        for (int i = 0; i < n; ++i) {
            if (s[i] == 0) {
                if (current_char > 'z') return ""; // Exceeded alphabet limit
                s[i] = current_char++;
            }
            for (int j = i + 1; j < n; ++j) {
                if (lcp[i][j] > 0) {
                    if (s[j] == 0) {
                        s[j] = s[i];
                    }
                }
            }
        }

        // Step 2: Validate the constructed string against the given LCP matrix
        std::vector<std::vector<int>> actual_lcp(n + 1, std::vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == s[j]) {
                    actual_lcp[i][j] = 1 + actual_lcp[i + 1][j + 1];
                } else {
                    actual_lcp[i][j] = 0;
                }

                if (actual_lcp[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }

        return s;
    }
};