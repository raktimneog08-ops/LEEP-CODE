class Solution {
public:
    int reverseDegree(string s) {
        int totalDegree = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Calculate reverse alphabet position (e.g., 'a' -> 26, 'b' -> 25)
            int revAlphaPos = 26 - (s[i] - 'a');
            
            // Multiply by the 1-indexed string position
            totalDegree += revAlphaPos * (i + 1);
        }
        
        return totalDegree;
    }
};