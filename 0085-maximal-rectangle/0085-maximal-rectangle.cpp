#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        // Add an extra 0 at the end to ensure the stack is fully emptied at the end of each row
        vector<int> heights(cols + 1, 0); 
        int maxArea = 0;
        
        for (int r = 0; r < rows; ++r) {
            // 1. Update the histogram heights for the current row
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == '1') {
                    heights[c]++;
                } else {
                    heights[c] = 0;
                }
            }
            
            // 2. Calculate the maximum area for the current histogram using a Monotonic Stack
            stack<int> st;
            for (int i = 0; i < heights.size(); ++i) {
                // If we find a shorter bar, calculate the area of the taller bars in the stack
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    int h = heights[st.top()];
                    st.pop();
                    
                    // Width is determined by the current index and the new top of the stack
                    int w = st.empty() ? i : i - st.top() - 1;
                    maxArea = max(maxArea, h * w);
                }
                st.push(i);
            }
        }
        
        return maxArea;
    }
};