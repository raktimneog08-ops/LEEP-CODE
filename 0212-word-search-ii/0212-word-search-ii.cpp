#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string word = "";
};

class Solution {
private:
    TrieNode* root;

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& result) {
        char ch = board[r][c];
        if (ch == '#' || !node->children[ch - 'a']) {
            return;
        }

        node = node->children[ch - 'a'];

        // Found a word in the dictionary
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = ""; // Prevent duplicate matches
        }

        // Mark cell as visited
        board[r][c] = '#';

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '#') {
                dfs(board, nr, nc, node, result);
            }
        }

        // Restore cell
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (const string& word : words) {
            insert(word);
        }

        vector<string> result;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};