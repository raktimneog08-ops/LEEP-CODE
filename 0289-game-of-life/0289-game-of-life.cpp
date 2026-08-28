class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // 8-directional neighbor offsets
        int dirs[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        // First pass: encode transitions using state flags
        //  0 -> 0 :  0 (dead stays dead)
        //  1 -> 1 :  1 (live stays live)
        //  1 -> 0 : -1 (live becomes dead)
        //  0 -> 1 :  2 (dead becomes live)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = 0;

                for (auto& dir : dirs) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        // Cells with value 1 or -1 were originally live
                        if (abs(board[ni][nj]) == 1) {
                            liveNeighbors++;
                        }
                    }
                }

                // Rule 1 & 3: Live cell dies
                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[i][j] = -1;
                }
                // Rule 4: Dead cell becomes live
                else if (board[i][j] == 0 && liveNeighbors == 3) {
                    board[i][j] = 2;
                }
            }
        }

        // Second pass: finalize to 0 and 1
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] > 0) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};