class Solution {
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> dfs(const string& s, int start) {
        // If we've already computed the result for this starting index, return it
        if (memo.count(start)) {
            return memo[start];
        }
        
        vector<string> res;
        // Base case: if we reach the end of the string, return an empty string to build upon
        if (start == s.length()) {
            res.push_back("");
            return res;
        }

        // Try every possible end index for the first word
        for (int end = start + 1; end <= s.length(); ++end) {
            string word = s.substr(start, end - start);
            
            // If the word exists in the dictionary, find all combinations for the rest of the string
            if (dict.count(word)) {
                vector<string> sublist = dfs(s, end);
                for (const string& sub : sublist) {
                    // Append the current word to the results of the subproblem
                    res.push_back(word + (sub.empty() ? "" : " ") + sub);
                }
            }
        }
        
        // Memoize and return the result for the current starting index
        return memo[start] = res;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Store dictionary words in a hash set for O(1) fast lookups
        for (const string& word : wordDict) {
            dict.insert(word);
        }
        
        // Start DFS from the 0th index
        return dfs(s, 0);
    }
};