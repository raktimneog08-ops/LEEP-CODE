#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_count = 0;
        int odd_char = -1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                odd_char = i;
            }
        }

        if ((n % 2 == 0 && odd_count > 0) || (n % 2 != 0 && odd_count != 1)) {
            return "";
        }

        int m = n / 2;
        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }

        // Try prefix lengths of the first half from m down to 0
        for (int i = m; i >= 0; --i) {
            // Verify if target[0...i-1] can be formed using half_count
            vector<int> cur_count = half_count;
            bool prefix_possible = true;
            for (int k = 0; k < i; ++k) {
                int c = target[k] - 'a';
                if (cur_count[c] <= 0) {
                    prefix_possible = false;
                    break;
                }
                cur_count[c]--;
            }
            if (!prefix_possible) continue;

            // If prefix matches all m characters
            if (i == m) {
                string first_half = target.substr(0, m);
                string pal = first_half;
                if (n % 2 != 0) {
                    pal += (char)('a' + odd_char);
                }
                string rev_half = first_half;
                reverse(rev_half.begin(), rev_half.end());
                pal += rev_half;

                if (pal > target) {
                    return pal;
                }
                continue;
            }

            // Otherwise, try character c > target[i] at position i
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (cur_count[c] > 0) {
                    cur_count[c]--;

                    string first_half = target.substr(0, i) + (char)('a' + c);
                    for (int ch = 0; ch < 26; ++ch) {
                        first_half += string(cur_count[ch], 'a' + ch);
                    }

                    string pal = first_half;
                    if (n % 2 != 0) {
                        pal += (char)('a' + odd_char);
                    }
                    string rev_half = first_half;
                    reverse(rev_half.begin(), rev_half.end());
                    pal += rev_half;

                    return pal;
                }
            }
        }

        return "";
    }
};