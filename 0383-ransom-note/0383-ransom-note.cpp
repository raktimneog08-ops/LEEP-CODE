class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int charCounts[26] = {0};
        
        // Count frequencies of each letter in the magazine
        for (char c : magazine) {
            charCounts[c - 'a']++;
        }
        
        // Check if ransomNote can be built from available letters
        for (char c : ransomNote) {
            charCounts[c - 'a']--;
            // If the count goes below 0, we don't have enough of this letter
            if (charCounts[c - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
};