#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Track visited numbers for rows, columns, and 3x3 boxes
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }

                int num = board[r][c] - '1'; // Map '1'-'9' to index 0-8
                int boxIndex = (r / 3) * 3 + (c / 3);

                // Check for duplicates
                if (rows[r][num] || cols[c][num] || boxes[boxIndex][num]) {
                    return false;
                }

                // Mark the number as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[boxIndex][num] = true;
            }
        }

        return true;
    }
};