#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < nums.size(); ++i) {
            pos[nums[i]].push_back(i);
        }

        int min_dist = INT_MAX;

        for (auto& pair : pos) {
            auto& indices = pair.second;
            if (indices.size() >= 3) {
                for (size_t i = 0; i + 2 < indices.size(); ++i) {
                    int idx1 = indices[i];
                    int idx3 = indices[i + 2];
                    int dist = 2 * (idx3 - idx1);
                    min_dist = min(min_dist, dist);
                }
            }
        }

        return min_dist == INT_MAX ? -1 : min_dist;
    }
};