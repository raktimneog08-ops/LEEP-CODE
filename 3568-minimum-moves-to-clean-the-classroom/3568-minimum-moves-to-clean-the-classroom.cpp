#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int start_r = -1, start_c = -1;
        int litter_count = 0;
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    start_r = r;
                    start_c = c;
                } else if (classroom[r][c] == 'L') {
                    litter_id[r][c] = litter_count++;
                }
            }
        }
        
        if (litter_count == 0) return 0;
        int target_mask = (1 << litter_count) - 1;
        
        // max_energy[r][c][mask]
        vector<vector<vector<int>>> max_energy(
            m, vector<vector<int>>(n, vector<int>(1 << litter_count, -1))
        );
        
        // Queue stores {row, col, mask, current_energy, steps}
        queue<tuple<int, int, int, int, int>> q;
        
        q.push({start_r, start_c, 0, energy, 0});
        max_energy[start_r][start_c][0] = energy;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [r, c, mask, curr_e, steps] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                    continue;
                }
                
                int next_e = curr_e - 1;
                if (next_e < 0) continue;
                
                int next_mask = mask;
                if (classroom[nr][nc] == 'L') {
                    next_mask |= (1 << litter_id[nr][nc]);
                } else if (classroom[nr][nc] == 'R') {
                    next_e = energy;
                }
                
                if (next_mask == target_mask) {
                    return steps + 1;
                }
                
                if (next_e > max_energy[nr][nc][next_mask]) {
                    max_energy[nr][nc][next_mask] = next_e;
                    q.push({nr, nc, next_mask, next_e, steps + 1});
                }
            }
        }
        
        return -1;
    }
};