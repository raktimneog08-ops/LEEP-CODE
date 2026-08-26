class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        // Quick check: board must contain at least enough cells for the word
        if (m * n < word.size()) return false;

        // Pruning optimization: check character frequencies
        unordered_map<char, int> board_freq;
        for (const auto& row : board) {
            for (char c : row) {
                board_freq[c]++;
            }
        }
        
        unordered_map<char, int> word_freq;
        for (char c : word) {
            word_freq[c]++;
            if (word_freq[c] > board_freq[c]) {
                return false;
            }
        }

        // Search from the direction with the rarer character at the start
        if (board_freq[word.front()] > board_freq[word.back()]) {
            reverse(word.begin(), word.end());
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int index) {
        if (index == word.size()) return true;
        
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }

        // Mark cell as visited by temporarily modifying the board in-place
        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);

        // Backtrack
        board[r][c] = temp;

        return found;
    }
};