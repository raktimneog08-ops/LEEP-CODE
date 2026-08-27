#include <string>
#include <vector>

class Solution {
public:
    std::string lexGreaterPermutation(std::string s, std::string target) {
        int n = s.length();
        std::vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Find the longest prefix of target that can be formed using s
        std::vector<int> prefix_count = count;
        int max_match = 0;
        while (max_match < n && prefix_count[target[max_match] - 'a'] > 0) {
            prefix_count[target[max_match] - 'a']--;
            max_match++;
        }

        // Try diverging at index i from max_match down to 0
        for (int i = std::min(n - 1, max_match); i >= 0; --i) {
            // Reconstruct available character counts after using target[0...i-1]
            std::vector<int> rem_count = count;
            for (int j = 0; j < i; ++j) {
                rem_count[target[j] - 'a']--;
            }

            // Find the smallest character strictly greater than target[i]
            int bump_char = -1;
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (rem_count[c] > 0) {
                    bump_char = c;
                    break;
                }
            }

            if (bump_char != -1) {
                std::string result = target.substr(0, i);
                result += static_cast<char>('a' + bump_char);
                rem_count[bump_char]--;

                // Append remaining characters in ascending sorted order
                for (int c = 0; c < 26; ++c) {
                    while (rem_count[c] > 0) {
                        result += static_cast<char>('a' + c);
                        rem_count[c]--;
                    }
                }
                return result;
            }
        }

        return "";
    }
};