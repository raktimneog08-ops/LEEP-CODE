class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        
        // Iterate through each pattern in the array
        for (const string& pattern : patterns) {
            // string::find returns string::npos if the pattern is not found
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }
        
        return count;
    }
};