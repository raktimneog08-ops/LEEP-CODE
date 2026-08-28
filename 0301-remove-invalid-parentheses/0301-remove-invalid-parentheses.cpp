class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int remL = 0, remR = 0;
        for (char c : s) {
            if (c == '(') {
                remL++;
            } else if (c == ')') {
                if (remL > 0) {
                    remL--;
                } else {
                    remR++;
                }
            }
        }

        unordered_set<string> resultSet;
        string current = "";
        dfs(0, 0, remL, remR, s, current, resultSet);
        return vector<string>(resultSet.begin(), resultSet.end());
    }

private:
    void dfs(int index, int balance, int remL, int remR, const string& s, string& current, unordered_set<string>& result) {
        if (balance < 0) return;

        if (index == s.length()) {
            if (remL == 0 && remR == 0 && balance == 0) {
                result.insert(current);
            }
            return;
        }

        char c = s[index];

        if (c == '(') {
            // Option 1: Remove '('
            if (remL > 0) {
                dfs(index + 1, balance, remL - 1, remR, s, current, result);
            }
            // Option 2: Keep '('
            current.push_back(c);
            dfs(index + 1, balance + 1, remL, remR, s, current, result);
            current.pop_back();
        } else if (c == ')') {
            // Option 1: Remove ')'
            if (remR > 0) {
                dfs(index + 1, balance, remL, remR - 1, s, current, result);
            }
            // Option 2: Keep ')'
            current.push_back(c);
            dfs(index + 1, balance - 1, remL, remR, s, current, result);
            current.pop_back();
        } else {
            // Keep letters
            current.push_back(c);
            dfs(index + 1, balance, remL, remR, s, current, result);
            current.pop_back();
        }
    }
};