#include <vector>

using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            long long v = q[3];
            
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }
        
        int xor_sum = 0;
        for (int num : nums) {
            xor_sum ^= num;
        }
        
        return xor_sum;
    }
};