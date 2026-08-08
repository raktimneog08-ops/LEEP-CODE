#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> validSequence(std::string word1, std::string word2) {
        int n = word1.length();
        int m = word2.length();

        // last[i] stores the largest index in word1 from which word2[i...m-1] can be matched
        std::vector<int> last(m + 1, -1);
        last[m] = n;

        int ptr = n - 1;
        for (int i = m - 1; i >= 0; --i) {
            while (ptr >= 0 && word1[ptr] != word2[i]) {
                --ptr;
            }
            last[i] = ptr;
            if (ptr >= 0) {
                --ptr;
            }
        }

        std::vector<int> ans;
        bool usedMismatch = false;
        int j = 0; // Pointer for word1

        for (int i = 0; i < m; ++i) {
            while (j < n) {
                if (word1[j] == word2[i]) {
                    // Exact match
                    ans.push_back(j);
                    ++j;
                    break;
                } else if (!usedMismatch && last[i + 1] > j) {
                    // Use the single allowed mismatch
                    usedMismatch = true;
                    ans.push_back(j);
                    ++j;
                    break;
                }
                ++j;
            }
        }

        return ans.size() == m ? ans : std::vector<int>();
    }
};