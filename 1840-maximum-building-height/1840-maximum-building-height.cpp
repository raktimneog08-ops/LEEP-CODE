#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Add the implicit restrictions for the first and last buildings
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        
        // Sort restrictions by building ID
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        // Left-to-right pass to propagate height limits forward
        for (int i = 1; i < m; ++i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + (restrictions[i][0] - restrictions[i-1][0]));
        }
        
        // Right-to-left pass to propagate height limits backward
        for (int i = m - 2; i >= 0; --i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + (restrictions[i+1][0] - restrictions[i][0]));
        }
        
        int max_height = 0;
        
        // Calculate the maximum height reachable between any two adjacent restrictions
        for (int i = 1; i < m; ++i) {
            int h1 = restrictions[i-1][1];
            int h2 = restrictions[i][1];
            int id1 = restrictions[i-1][0];
            int id2 = restrictions[i][0];
            
            int current_peak = (h1 + h2 + id2 - id1) / 2;
            max_height = max(max_height, current_peak);
        }
        
        return max_height;
    }
};