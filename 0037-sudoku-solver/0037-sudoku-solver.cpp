#include <vector>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(std::vector<std::vector<char>>& board) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    for (char ch = '1'; ch <= '9'; ++ch) {
                        if (isValid(board, r, c, ch)) {
                            board[r][c] = ch;

                            if (solve(board)) {
                                return true;
                            }

                            // Backtrack
                            board[r][c] = '.';
                        }
                    }
                    return false; // No valid digit found for this cell
                }
            }
        }
        return true; // Entire board filled successfully
    }

    bool isValid(const std::vector<std::vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; ++i) {
            // Check row
            if (board[row][i] == ch) return false;
            // Check column
            if (board[i][col] == ch) return false;
            // Check 3x3 sub-box
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) return false;
        }
        return true;
    }
};