class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        for (int i = 0; i < numRows; i++) {
            // Initialize the current row with all 1s. The size is i + 1.
            vector<int> row(i + 1, 1);
            
            // Calculate the intermediate values (skip the first and last elements)
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            // Add the computed row to the triangle
            triangle.push_back(row);
        }
        
        return triangle;
    }
};