#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        std::string current = "1";

        for (int i = 1; i < n; ++i) {
            std::string next = "";
            int count = 1;

            for (int j = 0; j < current.length(); ++j) {
                // If the next character is the same, increment the count
                if (j + 1 < current.length() && current[j] == current[j + 1]) {
                    ++count;
                } else {
                    // Append count and character
                    next += std::to_string(count) + current[j];
                    count = 1; // Reset count for the next character group
                }
            }

            current = next;
        }

        return current;
    }
};