#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        
        while (top <= bottom && left <= right) {
            // 1. Traverse from Left to Right along the top boundary
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            top++; // Move the top boundary down
            
            // 2. Traverse from Top to Bottom along the right boundary
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--; // Move the right boundary left
            
            // 3. Traverse from Right to Left along the bottom boundary
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--; // Move the bottom boundary up
            }
            
            // 4. Traverse from Bottom to Top along the left boundary
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Move the left boundary right
            }
        }
        
        return result;
    }
};