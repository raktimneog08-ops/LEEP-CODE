class Solution {
public:
    int findGCD(vector<int>& nums) {
        // Find the minimum and maximum elements in the array
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        
        // Calculate and return their Greatest Common Divisor (GCD)
        return std::gcd(min_val, max_val);
    }
};