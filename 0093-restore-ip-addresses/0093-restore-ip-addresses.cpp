#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> result;
        if (s.length() < 4 || s.length() > 12) {
            return result;
        }
        
        std::vector<std::string> current_segments;
        backtrack(s, 0, current_segments, result);
        return result;
    }

private:
    void backtrack(const std::string& s, int start, std::vector<std::string>& current, std::vector<std::string>& result) {
        // Base case: formed 4 segments
        if (current.size() == 4) {
            if (start == s.length()) {
                result.push_back(current[0] + "." + current[1] + "." + current[2] + "." + current[3]);
            }
            return;
        }

        // Try segments of length 1, 2, and 3
        for (int len = 1; len <= 3 && start + len <= s.length(); ++len) {
            std::string segment = s.substr(start, len);
            
            // Check for leading zero
            if (len > 1 && segment[0] == '0') {
                break;
            }
            
            // Check range [0, 255]
            int val = std::stoi(segment);
            if (val > 255) {
                break;
            }

            current.push_back(segment);
            backtrack(s, start + len, current, result);
            current.pop_back();
        }
    }
};