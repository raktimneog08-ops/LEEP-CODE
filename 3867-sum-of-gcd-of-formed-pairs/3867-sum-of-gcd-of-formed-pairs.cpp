#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int currentMax = 0;
        
        // Step 1: Construct the prefixGcd array
        for (int i = 0; i < n; ++i) {
            currentMax = max(currentMax, nums[i]);
            prefixGcd[i] = std::gcd(nums[i], currentMax);
        }
        
        // Step 2: Sort the constructed array
        sort(prefixGcd.begin(), prefixGcd.end());
        
        // Step 3: Use two pointers to pair smallest and largest elements
        long long totalSum = 0;
        int left = 0;
        int right = n - 1;
        
        while (left < right) {
            totalSum += std::gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        
        // Step 4: Return the accumulated sum
        return totalSum;
    }
};