#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestNumber(string num, long long t) {

        // ------------------------------------------------------------
        // 1. Factor t into 2, 3, 5, 7
        // ------------------------------------------------------------
        int R2 = 0, R3 = 0, R5 = 0, R7 = 0;

        while (t % 2 == 0) {
            ++R2;
            t /= 2;
        }

        while (t % 3 == 0) {
            ++R3;
            t /= 3;
        }

        while (t % 5 == 0) {
            ++R5;
            t /= 5;
        }

        while (t % 7 == 0) {
            ++R7;
            t /= 7;
        }

        // If t has a prime factor other than 2,3,5,7,
        // no product of digits 1..9 can be divisible by t.
        if (t != 1) {
            return "-1";
        }

        // ------------------------------------------------------------
        // Prime factor contribution of every digit
        // ------------------------------------------------------------
        int e2[10] = {0, 0, 1, 0, 2, 0, 1, 0, 3, 0};
        int e3[10] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 2};
        int e5[10] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
        int e7[10] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};

        // ------------------------------------------------------------
        // 2. DP
        //
        // dp[a][b][c][d] =
        // minimum number of digits needed to obtain at least:
        // 2^a * 3^b * 5^c * 7^d
        // ------------------------------------------------------------
        const int INF = 1e9;

        int S2 = R2 + 1;
        int S3 = R3 + 1;
        int S5 = R5 + 1;
        int S7 = R7 + 1;

        long long totalStates =
            1LL * S2 * S3 * S5 * S7;

        vector<int> dp((size_t)totalStates, INF);

        auto id = [&](int a, int b, int c, int d) -> int {
            return (((a * S3 + b) * S5 + c) * S7 + d);
        };

        dp[id(0, 0, 0, 0)] = 0;

        for (int a = 0; a <= R2; ++a) {
            for (int b = 0; b <= R3; ++b) {
                for (int c = 0; c <= R5; ++c) {
                    for (int d = 0; d <= R7; ++d) {

                        int cur = dp[id(a, b, c, d)];

                        if (cur == INF) {
                            continue;
                        }

                        // Digits 2..9.
                        // Digit 1 contributes nothing, so it never
                        // helps minimize the number of required digits.
                        for (int digit = 2; digit <= 9; ++digit) {

                            int na = min(R2, a + e2[digit]);
                            int nb = min(R3, b + e3[digit]);
                            int nc = min(R5, c + e5[digit]);
                            int nd = min(R7, d + e7[digit]);

                            int nxt = id(na, nb, nc, nd);

                            dp[nxt] = min(dp[nxt], cur + 1);
                        }
                    }
                }
            }
        }

        auto minRequiredDigits =
            [&](int a, int b, int c, int d) -> int {
                return dp[id(a, b, c, d)];
            };

        // ------------------------------------------------------------
        // 3. Build the lexicographically smallest suffix
        // ------------------------------------------------------------
        auto buildSuffix =
            [&](int len,
                int need2,
                int need3,
                int need5,
                int need7) -> string {

                string res;
                res.reserve(len);

                for (int pos = 0; pos < len; ++pos) {

                    int remaining = len - pos - 1;
                    bool chosen = false;

                    // Digits are tried from smallest to largest.
                    for (int digit = 1; digit <= 9; ++digit) {

                        int n2 = max(0, need2 - e2[digit]);
                        int n3 = max(0, need3 - e3[digit]);
                        int n5 = max(0, need5 - e5[digit]);
                        int n7 = max(0, need7 - e7[digit]);

                        if (minRequiredDigits(
                                n2, n3, n5, n7
                            ) <= remaining) {

                            res.push_back(char('0' + digit));

                            need2 = n2;
                            need3 = n3;
                            need5 = n5;
                            need7 = n7;

                            chosen = true;
                            break;
                        }
                    }

                    // This should not happen if the caller supplied
                    // a feasible length.
                    if (!chosen) {
                        return "";
                    }
                }

                return res;
            };

        int n = (int)num.size();

        // ------------------------------------------------------------
        // 4. Check num itself
        // ------------------------------------------------------------
        bool zeroFree = true;

        int cur2 = 0;
        int cur3 = 0;
        int cur5 = 0;
        int cur7 = 0;

        for (char ch : num) {

            int digit = ch - '0';

            if (digit == 0) {
                zeroFree = false;
                break;
            }

            cur2 = min(R2, cur2 + e2[digit]);
            cur3 = min(R3, cur3 + e3[digit]);
            cur5 = min(R5, cur5 + e5[digit]);
            cur7 = min(R7, cur7 + e7[digit]);
        }

        if (zeroFree &&
            cur2 >= R2 &&
            cur3 >= R3 &&
            cur5 >= R5 &&
            cur7 >= R7) {

            return num;
        }

        // ------------------------------------------------------------
        // 5. Prefix prime-factor contributions
        // ------------------------------------------------------------
        vector<int> pref2(n + 1, 0);
        vector<int> pref3(n + 1, 0);
        vector<int> pref5(n + 1, 0);
        vector<int> pref7(n + 1, 0);

        for (int i = 0; i < n; ++i) {

            int digit = num[i] - '0';

            pref2[i + 1] =
                min(R2, pref2[i] + e2[digit]);

            pref3[i + 1] =
                min(R3, pref3[i] + e3[digit]);

            pref5[i + 1] =
                min(R5, pref5[i] + e5[digit]);

            pref7[i + 1] =
                min(R7, pref7[i] + e7[digit]);
        }

        // ------------------------------------------------------------
        // 6. Find the first zero
        //
        // A valid same-length answer cannot keep a prefix containing
        // zero, because the answer itself must be zero-free.
        // ------------------------------------------------------------
        int firstZero = n;

        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                firstZero = i;
                break;
            }
        }

        // ------------------------------------------------------------
        // 7. Try to find the smallest valid number of the same length
        //
        // We modify the RIGHTMOST possible position, because that
        // gives the smallest resulting number.
        // ------------------------------------------------------------
        for (int i = min(n - 1, firstZero); i >= 0; --i) {

            int originalDigit = num[i] - '0';

            // The new digit must be strictly larger.
            for (int digit = max(1, originalDigit + 1);
                 digit <= 9;
                 ++digit) {

                int have2 =
                    min(R2, pref2[i] + e2[digit]);

                int have3 =
                    min(R3, pref3[i] + e3[digit]);

                int have5 =
                    min(R5, pref5[i] + e5[digit]);

                int have7 =
                    min(R7, pref7[i] + e7[digit]);

                int need2 = R2 - have2;
                int need3 = R3 - have3;
                int need5 = R5 - have5;
                int need7 = R7 - have7;

                int suffixLen = n - i - 1;

                if (minRequiredDigits(
                        need2,
                        need3,
                        need5,
                        need7
                    ) <= suffixLen) {

                    string answer;

                    // Original prefix
                    answer += num.substr(0, i);

                    // Increased digit
                    answer.push_back(char('0' + digit));

                    // Smallest possible suffix
                    answer += buildSuffix(
                        suffixLen,
                        need2,
                        need3,
                        need5,
                        need7
                    );

                    return answer;
                }
            }
        }

        // ------------------------------------------------------------
        // 8. Same-length solution does not exist.
        //
        // Any number with n+1 digits is automatically greater than num.
        //
        // IMPORTANT:
        // n+1 may still be too short to contain enough prime factors,
        // so we must take the maximum of:
        //
        //   n+1
        //   minimum digits actually required
        // ------------------------------------------------------------
        int minLen =
            minRequiredDigits(R2, R3, R5, R7);

        int len = max(n + 1, minLen);

        return buildSuffix(
            len,
            R2,
            R3,
            R5,
            R7
        );
    }
};