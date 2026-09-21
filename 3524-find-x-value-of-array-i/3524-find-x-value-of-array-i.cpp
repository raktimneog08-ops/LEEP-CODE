class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        // result[x] will store the count of subarrays whose product % k == x
        vector<long long> result(k, 0);
        
        // Stores the frequencies of remainders for subarrays ending at the previous index
        vector<pair<int, long long>> active;
        
        // Temporary storage for the current step to avoid O(k) initialization per element
        vector<long long> temp(k, 0);
        vector<int> active_keys;
        
        for (int x : nums) {
            long long val = x % k;
            
            // 1. The subarray starting and ending at the current element itself
            if (temp[val] == 0) {
                active_keys.push_back(val);
            }
            temp[val]++;
            
            // 2. Extend all valid subarrays from the previous index
            for (const auto& p : active) {
                int nxt = (p.first * val) % k;
                if (temp[nxt] == 0) {
                    active_keys.push_back(nxt);
                }
                temp[nxt] += p.second;
            }
            
            // 3. Update the active states and accumulate results
            active.clear();
            for (int key : active_keys) {
                active.emplace_back(key, temp[key]);
                result[key] += temp[key];
                
                // Reset temp array for the next iteration
                temp[key] = 0; 
            }
            active_keys.clear();
        }
        
        return result;
    }
};