#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int max_dist = 0;
        
        // Compare with the first house
        for (int i = n - 1; i >= 0; --i) {
            if (colors[i] != colors[0]) {
                max_dist = max(max_dist, i);
                break;
            }
        }
        
        // Compare with the last house
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors[n - 1]) {
                max_dist = max(max_dist, (n - 1) - i);
                break;
            }
        }
        
        return max_dist;
    }
};