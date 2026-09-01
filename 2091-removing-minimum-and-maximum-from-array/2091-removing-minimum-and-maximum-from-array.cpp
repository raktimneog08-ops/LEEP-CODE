#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int min_idx = 0;
        int max_idx = 0;

        for (int k = 1; k < n; ++k) {
            if (nums[k] < nums[min_idx]) min_idx = k;
            if (nums[k] > nums[max_idx]) max_idx = k;
        }

        int i = min(min_idx, max_idx);
        int j = max(min_idx, max_idx);

        // 1. Remove both from front
        int remove_front = j + 1;

        // 2. Remove both from back
        int remove_back = n - i;

        // 3. Remove one from front and one from back
        int remove_both_ends = (i + 1) + (n - j);

        return min({remove_front, remove_back, remove_both_ends});
    }
};