#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    unordered_map<string, bool> memo;

public:
    bool isScramble(string s1, string s2) {
        // Base case: if the strings are identical
        if (s1 == s2) return true;
        
        // Length check (though the problem guarantees they are equal length)
        if (s1.length() != s2.length()) return false;
        
        // Check if we have already solved this subproblem
        string key = s1 + "#" + s2;
        if (memo.count(key)) return memo[key];
        
        // Pruning: check if both strings have the exact same character frequencies
        int count[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return memo[key] = false;
            }
        }
        
        int n = s1.length();
        
        // Try all possible split points
        for (int i = 1; i < n; i++) {
            // Case 1: Substrings are NOT swapped
            // s1[0...i-1] with s2[0...i-1] AND s1[i...n-1] with s2[i...n-1]
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }
            
            // Case 2: Substrings ARE swapped
            // s1[0...i-1] with s2[n-i...n-1] AND s1[i...n-1] with s2[0...n-i-1]
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && 
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }
        
        // If no split makes them scrambled versions of each other
        return memo[key] = false;
    }
};