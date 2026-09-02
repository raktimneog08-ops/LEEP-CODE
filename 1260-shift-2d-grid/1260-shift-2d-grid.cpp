class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElements = m * n;
        
        // Optimize k in case it's larger than the total number of elements
        k = k % totalElements;
        if (k == 0) return grid;
        
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Convert 2D index to 1D index
                int flatIndex = i * n + j;
                
                // Shift the 1D index by k
                int newFlatIndex = (flatIndex + k) % totalElements;
                
                // Convert the new 1D index back to 2D coordinates
                int newRow = newFlatIndex / n;
                int newCol = newFlatIndex % n;
                
                // Place the element in its new position
                result[newRow][newCol] = grid[i][j];
            }
        }
        
        return result;
    }
};