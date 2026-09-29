#include <vector>

class Solution {
public:
    bool hasValidPath(std::vector<std::vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 1. A valid parentheses string must have an even length (m + n - 1)
        if ((m + n) % 2 == 0) return false;
        
        // 2. Start must be '(' and end must be ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        
        // Max possible balance can reach m + n during intermediate steps
        int max_bal = m + n;
        // memo[r][c][bal] -> -1: unvisited, 0: false, 1: true
        std::vector<std::vector<std::vector<int>>> memo(
            m, std::vector<std::vector<int>>(n, std::vector<int>(max_bal + 1, -1))
        );
        
        auto dfs = [&](auto& self, int r, int c, int bal) -> bool {
            // Update balance based on the current cell character
            if (grid[r][c] == '(') {
                bal++;
            } else {
                bal--;
            }
            
            // If balance drops below 0, prefix is invalid
            if (bal < 0) return false;
            
            // If balance exceeds the remaining steps, it's impossible to reach 0
            if (bal > (m - 1 - r) + (n - 1 - c)) return false;
            
            // If we reached the bottom-right cell
            if (r == m - 1 && c == n - 1) {
                return bal == 0;
            }
            
            // Return memoized result if already computed
            if (memo[r][c][bal] != -1) {
                return memo[r][c][bal];
            }
            
            bool res = false;
            // Move down
            if (r + 1 < m) {
                res = res || self(self, r + 1, c, bal);
            }
            // Move right (only if down didn't already succeed)
            if (c + 1 < n && !res) {
                res = res || self(self, r, c + 1, bal);
            }
            
            return memo[r][c][bal] = res;
        };
        
        return dfs(dfs, 0, 0, 0);
    }
};