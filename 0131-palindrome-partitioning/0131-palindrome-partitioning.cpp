class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        
        // dp[i][j] will be true if s[i..j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int right = 0; right < n; ++right) {
            for (int left = 0; left <= right; ++left) {
                if (s[left] == s[right] && (right - left <= 2 || dp[left + 1][right - 1])) {
                    dp[left][right] = true;
                }
            }
        }

        vector<vector<string>> result;
        vector<string> currentPartition;
        
        backtrack(0, s, dp, currentPartition, result);
        return result;
    }

private:
    void backtrack(int start, const string& s, const vector<vector<bool>>& dp,
                   vector<string>& currentPartition, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(currentPartition);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (dp[start][end]) {
                currentPartition.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, dp, currentPartition, result);
                currentPartition.pop_back(); // backtrack
            }
        }
    }
};