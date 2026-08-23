#include <string>

class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.size();
        int sum_diff = 0; // sum(left) - sum(right)
        int q_diff = 0;   // count_q(left) - count_q(right)

        for (int i = 0; i < n; ++i) {
            int sign = (i < n / 2) ? 1 : -1;
            if (num[i] == '?') {
                q_diff += sign;
            } else {
                sum_diff += sign * (num[i] - '0');
            }
        }

        // Alice wins if total '?' is odd
        // or if the sum difference cannot be exactly neutralized by the '?' difference
        // Condition for Bob's win: sum_diff == (q2 - q1) / 2 * 9  =>  2 * sum_diff == -q_diff * 9
        return (2 * sum_diff + q_diff * 9) != 0;
    }
};
