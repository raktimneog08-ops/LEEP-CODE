#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int min_dist = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                int dist1 = abs(i - startIndex);
                int dist2 = n - dist1;
                int current_dist = min(dist1, dist2);
                min_dist = min(min_dist, current_dist);
            }
        }
        
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};