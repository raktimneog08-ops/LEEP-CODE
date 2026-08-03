#include <vector>
#include <string>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string current, int open_count, int close_count, int max_pairs) {
        // Base case: if the current string length equals 2 * n, we've formed a valid combination
        if (current.length() == max_pairs * 2) {
            result.push_back(current);
            return;
        }

        // Option 1: Add an open parenthesis if we haven't reached the limit 'n'
        if (open_count < max_pairs) {
            backtrack(result, current + "(", open_count + 1, close_count, max_pairs);
        }

        // Option 2: Add a close parenthesis if it won't exceed the number of open parentheses
        if (close_count < open_count) {
            backtrack(result, current + ")", open_count, close_count + 1, max_pairs);
        }
    }
};