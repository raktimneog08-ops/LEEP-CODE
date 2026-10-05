#include <string>
#include <algorithm>

class Solution {
public:
    int scoreOfParentheses(std::string s) {
        int score = 0;
        int depth = 0;
        
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                // If we encounter a closing parenthesis immediately following an opening one,
                // it forms a "()", which contributes 2^(depth) to the total score.
                if (s[i - 1] == '(') {
                    score += (1 << depth); // Equivalent to 2^depth
                }
            }
        }
        
        return score;
    }
};