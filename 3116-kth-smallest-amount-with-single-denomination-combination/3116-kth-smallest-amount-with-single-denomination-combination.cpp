#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        int n = coins.size();
        
        // The maximum possible answer would be if we only used the smallest coin
        long long min_coin = *std::min_element(coins.begin(), coins.end());
        long long high = min_coin * k;
        long long low = 1;
        
        // Precompute the subsets' LCM and their Inclusion-Exclusion sign
        std::vector<std::pair<long long, int>> pie;
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long curr_lcm = 1;
            int bits = 0;
            bool overflow = false;
            
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    bits++;
                    long long g = std::gcd(curr_lcm, (long long)coins[i]);
                    
                    // Prevent overflow before calculating the new LCM
                    if (curr_lcm / g > high / coins[i]) {
                        overflow = true;
                        break;
                    }
                    curr_lcm = std::lcm(curr_lcm, (long long)coins[i]);
                }
            }
            
            // If the subset's LCM is within bounds, store it with its PIE sign
            if (!overflow) {
                pie.push_back({curr_lcm, (bits % 2 == 1) ? 1 : -1});
            }
        }
        
        long long ans = high;
        
        // Binary search the answer space
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            
            // Apply Inclusion-Exclusion
            for (auto& p : pie) {
                count += p.second * (mid / p.first);
            }
            
            if (count >= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid amount
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};