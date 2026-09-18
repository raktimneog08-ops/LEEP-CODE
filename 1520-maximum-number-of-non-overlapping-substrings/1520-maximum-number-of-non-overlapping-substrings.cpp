class Solution {
public:
    // Helper function to find the valid right bound of a substring starting at index i
    int checkSubstr(const string& s, int i, const vector<int>& L, const vector<int>& R) {
        int right = R[s[i] - 'a'];
        for (int j = i; j <= right; ++j) {
            // If a character inside expands to the left of our start point, it's invalid
            if (L[s[j] - 'a'] < i) {
                return -1;
            }
            // Expand the right boundary if necessary
            right = max(right, R[s[j] - 'a']);
        }
        return right;
    }

    vector<string> maxNumOfSubstrings(string s) {
        vector<int> L(26, -1), R(26, -1);
        int n = s.length();
        
        // Step 1: Record the first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            if (L[s[i] - 'a'] == -1) {
                L[s[i] - 'a'] = i;
            }
            R[s[i] - 'a'] = i;
        }

        vector<string> res;
        int right = -1;
        
        // Step 2 & 3: Find valid substrings and greedily select them
        for (int i = 0; i < n; ++i) {
            // Only attempt to start a substring at a character's first occurrence
            if (i == L[s[i] - 'a']) {
                int new_right = checkSubstr(s, i, L, R);
                
                if (new_right != -1) {
                    if (i > right) {
                        // Non-overlapping: append a new slot
                        res.push_back("");
                    }
                    // Overlapping (meaning it's fully contained inside the previous): 
                    // Replace previous with this smaller, tighter substring.
                    right = new_right;
                    res.back() = s.substr(i, right - i + 1);
                }
            }
        }
        
        return res;
    }
};