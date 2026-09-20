class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Track the minimum damage (health lost) to reach each cell
        vector<vector<int>> min_damage(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;
        
        min_damage[0][0] = grid[0][0];
        if (grid[0][0] == 1) {
            dq.push_back({0, 0});
        } else {
            dq.push_front({0, 0});
        }
        
        // Directions: Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int damage = grid[nr][nc];
                    
                    // If we found a safer path to the neighbor cell
                    if (min_damage[r][c] + damage < min_damage[nr][nc]) {
                        min_damage[nr][nc] = min_damage[r][c] + damage;
                        
                        // Push 0-cost moves to the front, 1-cost to the back
                        if (damage == 1) {
                            dq.push_back({nr, nc});
                        } else {
                            dq.push_front({nr, nc});
                        }
                    }
                }
            }
        }
        
        // Check if the remaining health after reaching the target is strictly positive
        return (health - min_damage[m - 1][n - 1]) >= 1;
    }
};