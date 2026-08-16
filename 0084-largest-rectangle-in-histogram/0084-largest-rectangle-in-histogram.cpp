#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        int n = heights.size();
        
        // Iterate one step past the end of the array to flush out remaining bars
        for (int i = 0; i <= n; i++) {
            // Treat the boundary past the last element as a height of 0
            int currentHeight = (i == n) ? 0 : heights[i];
            
            // If the current bar is shorter than the bar at the top of the stack,
            // we have found the right edge for the rectangle of the stack's top bar.
            while (!s.empty() && currentHeight < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                
                // If stack is empty, the width is the current index.
                // Otherwise, the width is the distance between the current index 
                // and the new top of the stack minus one.
                int w = s.empty() ? i : i - s.top() - 1;
                
                maxArea = max(maxArea, h * w);
            }
            // Push the current index onto the stack
            s.push(i);
        }
        
        return maxArea;
    }
};