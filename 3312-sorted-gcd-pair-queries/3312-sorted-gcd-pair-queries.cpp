#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> gcdValues(std::vector<int>& nums, std::vector<long long>& queries) {
        int max_val = *std::max_element(nums.begin(), nums.end());
        
        // Step 1: Count frequency of each number
        std::vector<int> freq(max_val + 1, 0);
        for (int x : nums) {
            freq[x]++;
        }

        // Step 2: Count how many numbers are multiples of each g
        std::vector<long long> count_multiples(max_val + 1, 0);
        for (int g = 1; g <= max_val; ++g) {
            for (int multiple = g; multiple <= max_val; multiple += g) {
                count_multiples[g] += freq[multiple];
            }
        }

        // Step 3: Compute exact GCD pair counts via Inclusion-Exclusion
        std::vector<long long> gcd_count(max_val + 1, 0);
        for (int g = max_val; g >= 1; --g) {
            long long total_pairs = count_multiples[g] * (count_multiples[g] - 1) / 2;
            for (int multiple = 2 * g; multiple <= max_val; multiple += g) {
                total_pairs -= gcd_count[multiple];
            }
            gcd_count[g] = total_pairs;
        }

        // Step 4: Prefix sums of GCD pair frequencies
        std::vector<long long> prefix_gcd(max_val + 1, 0);
        for (int g = 1; g <= max_val; ++g) {
            prefix_gcd[g] = prefix_gcd[g - 1] + gcd_count[g];
        }

        // Step 5: Answer each query via binary search
        std::vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            // Find smallest index where prefix_gcd[g] > q
            auto it = std::upper_bound(prefix_gcd.begin() + 1, prefix_gcd.end(), q);
            ans.push_back(std::distance(prefix_gcd.begin(), it));
        }

        return ans;
    }
};