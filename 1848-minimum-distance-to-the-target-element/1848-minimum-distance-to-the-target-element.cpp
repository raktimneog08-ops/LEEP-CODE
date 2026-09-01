#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int min_dist = INT_MAX;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                min_dist = min(min_dist, abs(i - start));
            }
        }
        
        return min_dist;
    }
};