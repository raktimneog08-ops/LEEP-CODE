class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == '1') {
                    count++;
                }
                
                if (count == k) {
                    string sub = s.substr(i, j - i + 1);
                    if (ans.empty() || sub.length() < ans.length() || 
                       (sub.length() == ans.length() && sub < ans)) {
                        ans = sub;
                    }
                    break; // Moving j further will only increase length
                }
            }
        }
        
        return ans;
    }
};