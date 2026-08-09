class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0;
        int starIdx = -1, match = -1;

        while (i < m) {
            // Case 1: Characters match or pattern has '?'
            if (j < n && (p[j] == '?' || s[i] == p[j])) {
                i++;
                j++;
            }
            // Case 2: Pattern has '*', track its position and the current string index
            else if (j < n && p[j] == '*') {
                starIdx = j;
                match = i;
                j++;
            }
            // Case 3: No match, but we have seen a '*' previously.
            // Backtrack to the last '*' and try matching one more character of 's'
            else if (starIdx != -1) {
                j = starIdx + 1;
                match++;
                i = match;
            }
            // Case 4: No match and no '*' to fallback on
            else {
                return false;
            }
        }

        // Consume any remaining '*' characters in the pattern
        while (j < n && p[j] == '*') {
            j++;
        }

        // If we have successfully traversed the entire pattern, it's a match
        return j == n;
    }
};