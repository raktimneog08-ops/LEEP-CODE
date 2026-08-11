class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        // Initialize an empty n x n board
        vector<string> board(n, string(n, '.'));
        
        // Arrays to keep track of attacked columns and diagonals
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false); // Anti-diagonals: row + col
        vector<bool> diag2(2 * n - 1, false); // Main diagonals: row - col + (n - 1)
        
        backtrack(0, board, result, cols, diag1, diag2, n);
        
        return result;
    }

private:
    void backtrack(int row, vector<string>& board, vector<vector<string>>& result, 
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, int n) {
        // Base case: If we successfully placed a queen in every row, add board to result
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; ++col) {
            int d1 = row + col;
            int d2 = row - col + n - 1;
            
            // If the current column or either diagonal is under attack, skip to the next column
            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue;
            }
            
            // Choose: Place the queen and mark the column/diagonals as attacked
            board[row][col] = 'Q';
            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            
            // Explore: Move to the next row
            backtrack(row + 1, board, result, cols, diag1, diag2, n);
            
            // Un-choose (Backtrack): Remove the queen and unmark the attacks
            board[row][col] = '.';
            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
};