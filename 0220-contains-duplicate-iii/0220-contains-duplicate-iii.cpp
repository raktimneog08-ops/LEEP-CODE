#include <vector>
#include <set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window;

        for (int i = 0; i < nums.size(); ++i) {
            long long val = nums[i];

            // Find the smallest element >= val - valueDiff
            auto it = window.lower_bound(val - valueDiff);

            // Check if this element also satisfies <= val + valueDiff
            if (it != window.end() && *it <= val + valueDiff) {
                return true;
            }

            window.insert(val);

            // Maintain sliding window of size indexDiff
            if (i >= indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }

        return false;
    }
};