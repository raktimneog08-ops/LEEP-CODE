#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};

        std::vector<std::string> pad = {
            "",     "",     "abc",  "def", 
            "ghi",  "jkl",  "mno",  "pqrs", 
            "tuv",  "wxyz"
        };

        std::vector<std::string> result;
        std::string current;

        backtrack(digits, 0, pad, current, result);
        return result;
    }

private:
    void backtrack(const std::string& digits, int index, const std::vector<std::string>& pad, 
                   std::string& current, std::vector<std::string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        std::string letters = pad[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, index + 1, pad, current, result);
            current.pop_back(); // backtrack
        }
    }
};