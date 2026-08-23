#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string token;

        // Split path by '/'
        while (std::getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(token);
            }
        }

        // Build the simplified canonical path
        if (stack.empty()) {
            return "/";
        }

        std::string result = "";
        for (const std::string& dir : stack) {
            result += "/" + dir;
        }

        return result;
    }
};