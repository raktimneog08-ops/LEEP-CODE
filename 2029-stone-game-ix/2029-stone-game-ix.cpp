#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        
        // Count the frequency of each remainder
        for (int stone : stones) {
            cnt[stone % 3]++;
        }

        // If the number of multiples of 3 is even
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        } 
        // If the number of multiples of 3 is odd
        else {
            return abs(cnt[1] - cnt[2]) > 2;
        }
    }
};