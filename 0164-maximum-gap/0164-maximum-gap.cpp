#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int minVal = *std::min_element(nums.begin(), nums.end());
        int maxVal = *std::max_element(nums.begin(), nums.end());

        if (minVal == maxVal) return 0;

        // Bucket configuration
        int bucketSize = std::max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        std::vector<int> minBucket(bucketCount, INT_MAX);
        std::vector<int> maxBucket(bucketCount, INT_MIN);

        // Distribute elements into buckets
        for (int num : nums) {
            int idx = (num - minVal) / bucketSize;
            minBucket[idx] = std::min(minBucket[idx], num);
            maxBucket[idx] = std::max(maxBucket[idx], num);
        }

        // Find the maximum gap between adjacent non-empty buckets
        int maxGap = 0;
        int prevMax = minVal;

        for (int i = 0; i < bucketCount; ++i) {
            // Skip empty buckets
            if (minBucket[i] == INT_MAX) continue;

            maxGap = std::max(maxGap, minBucket[i] - prevMax);
            prevMax = maxBucket[i];
        }

        return maxGap;
    }
};