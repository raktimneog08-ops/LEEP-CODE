#include <vector>

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        // Tracking arrays for columns and the two diagonals
        std::vector<bool> cols(n, false);
        std::vector<bool> diag1(2 * n, false);
        std::vector<bool> diag2(2 * n, false);
        
        backtrack(0, n, count, cols, diag1, diag2);
        
        return count;
    }
    
private:
    void backtrack(int row, int n, int& count, std::vector<bool>& cols, std::vector<bool>& diag1, std::vector<bool>& diag2) {
        // Base case: If we successfully placed a queen in every row, we found a valid solution
        if (row == n) {
            count++;
            return;
        }
        
        for (int col = 0; col < n; col++) {
            // Calculate diagonal indices
            // diag1 (top-left to bottom-right): row - col is constant, add 'n' to avoid negative indices
            int id1 = row - col + n; 
            // diag2 (top-right to bottom-left): row + col is constant
            int id2 = row + col;
            
            // Check if the current square is under attack
            if (cols[col] || diag1[id1] || diag2[id2]) {
                continue;
            }
            
            // Place the queen (mark column and diagonals as attacked)
            cols[col] = true;
            diag1[id1] = true;
            diag2[id2] = true;
            
            // Move to the next row
            backtrack(row + 1, n, count, cols, diag1, diag2);
            
            // Backtrack: Remove the queen and explore other positions
            cols[col] = false;
            diag1[id1] = false;
            diag2[id2] = false;
        }
    }
};