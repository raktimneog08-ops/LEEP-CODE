#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Edge case: A 1x1 grid is trivially valid because we are already at the destination.
        if (m == 1 && n == 1) return true; 
        
        // Directions mapping: 0: UP, 1: RIGHT, 2: DOWN, 3: LEFT
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        
        // Allowed outgoing directions for each street type. 
        // 1-indexed to match grid values (index 0 is left empty).
        vector<vector<int>> outgoing = {
            {},             // 0 (dummy)
            {1, 3},         // 1: RIGHT, LEFT
            {0, 2},         // 2: UP, DOWN
            {2, 3},         // 3: DOWN, LEFT
            {1, 2},         // 4: RIGHT, DOWN
            {0, 3},         // 5: UP, LEFT
            {0, 1}          // 6: UP, RIGHT
        };
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            // If we successfully reach the bottom-right cell, a valid path exists
            if (r == m - 1 && c == n - 1) {
                return true;
            }
            
            int current_street = grid[r][c];
            
            // Explore all valid exits from the current street piece
            for (int dir : outgoing[current_street]) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];
                
                // Ensure the move is within grid boundaries and not already visited
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int next_street = grid[nr][nc];
                    
                    // Calculate the direction required from the target cell to look BACK at us
                    int opposite_dir = (dir + 2) % 4; 
                    
                    // Check if the adjacent cell's street physically connects back to our cell
                    bool connects_back = false;
                    for (int next_dir : outgoing[next_street]) {
                        if (next_dir == opposite_dir) {
                            connects_back = true;
                            break;
                        }
                    }
                    
                    if (connects_back) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return false;
    }
};