#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, vector<int>> indices;
        
        for (int i = 0; i < n; ++i) {
            indices[nums[i]].push_back(i);
        }
        
        for (auto& pair : indices) {
            auto& pos = pair.second;
            int k = pos.size();
            if (k <= 1) continue;
            
            vector<long long> pref(k + 1, 0);
            for (int i = 0; i < k; ++i) {
                pref[i + 1] = pref[i] + pos[i];
            }
            
            for (int i = 0; i < k; ++i) {
                long long left_sum = (1LL * i * pos[i]) - pref[i];
                long long right_sum = (pref[k] - pref[i + 1]) - (1LL * (k - 1 - i) * pos[i]);
                ans[pos[i]] = left_sum + right_sum;
            }
        }
        
        return ans;
    }
};