#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        // 1D DP array initialized with infinity
        vector<int> dp(n + 1, INT_MAX);

        // Base cases: entering the Princess's cell requires at least 1 HP after exiting
        dp[n - 1] = 1;

        // Traverse backwards from bottom-right to top-left
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Minimum HP needed upon leaving (i, j)
                int minExitHP = (i == m - 1 && j == n - 1) ? 1 : min(dp[j], dp[j + 1]);
                
                // HP needed before entering (i, j)
                dp[j] = max(1, minExitHP - dungeon[i][j]);
            }
        }

        return dp[0];
    }
};