#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // Base case: if 1 row or enough rows to fit the whole string vertically
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Create a vector of strings for each row
        vector<string> rows(min(numRows, int(s.length())));
        
        int currRow = 0;
        bool goingDown = false;

        // Iterate through the characters and place them in the correct row
        for (char c : s) {
            rows[currRow] += c;
            
            // Change direction when we hit the top or bottom row
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move to the next row
            currRow += goingDown ? 1 : -1;
        }

        // Combine all rows into the final result string
        string result;
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};