#include <vector>
#include <algorithm>

class Solution {
public:
    int maxPathScore(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // Any valid path has exactly (m + n - 1) cells.
        // Therefore, the cost can never exceed (m + n - 1).
        int maxCost = std::min(k, m + n - 1);

        // dp[j][c] = max score at column j with total cost c
        // Initialize with -1 to indicate unreachable states
        std::vector<std::vector<int>> dp(n, std::vector<int>(maxCost + 1, -1));

        // Base case: Starting at (0, 0)
        // According to constraints, grid[0][0] == 0, so cost = 0, score = 0
        int startVal = grid[0][0];
        int startCost = (startVal == 0 ? 0 : 1);
        int startScore = startVal;

        if (startCost <= maxCost) {
            dp[0][startCost] = startScore;
        }

        // Fill DP table row by row
        for (int i = 0; i < m; ++i) {
            // Temporary row to accumulate transitions for row i
            std::vector<std::vector<int>> nextDp(n, std::vector<int>(maxCost + 1, -1));

            for (int j = 0; j < n; ++j) {
                int cellCost = (grid[i][j] == 0 ? 0 : 1);
                int cellScore = grid[i][j];

                // If at the start cell (0, 0)
                if (i == 0 && j == 0) {
                    if (startCost <= maxCost) {
                        nextDp[0][startCost] = startScore;
                    }
                    continue;
                }

                for (int c = cellCost; c <= maxCost; ++c) {
                    int prevCost = c - cellCost;
                    int bestPrevScore = -1;

                    // Transition from cell above (i - 1, j)
                    if (i > 0 && dp[j][prevCost] != -1) {
                        bestPrevScore = std::max(bestPrevScore, dp[j][prevCost]);
                    }

                    // Transition from cell to the left (i, j - 1)
                    if (j > 0 && nextDp[j - 1][prevCost] != -1) {
                        bestPrevScore = std::max(bestPrevScore, nextDp[j - 1][prevCost]);
                    }

                    if (bestPrevScore != -1) {
                        nextDp[j][c] = bestPrevScore + cellScore;
                    }
                }
            }

            dp = std::move(nextDp);
        }

        // Find the maximum score achieved at (m - 1, n - 1) across all valid costs <= maxCost
        int maxScore = -1;
        for (int c = 0; c <= maxCost; ++c) {
            maxScore = std::max(maxScore, dp[n - 1][c]);
        }

        return maxScore;
    }
};