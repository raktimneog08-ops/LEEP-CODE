class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        // If there are 2 or fewer points, they are always on the same line
        if (n <= 2) return n;
        
        int max_pts = 0;
        
        // Check lines originating from each point i
        for (int i = 0; i < n; ++i) {
            // Map to count how many points share the same reduced slope from point i
            map<pair<int, int>, int> slopeMap;
            int local_max = 0;
            
            // We only need to check points after i to avoid redundant calculations
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                // Reduce the fraction by dividing by the Greatest Common Divisor (GCD)
                int g = std::gcd(dx, dy);
                dx /= g;
                dy /= g;
                
                // Standardize the sign to ensure identical slopes map to the same key
                // (e.g., both -1/2 and 1/-2 become -1/2)
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }
                
                slopeMap[{dx, dy}]++;
                local_max = max(local_max, slopeMap[{dx, dy}]);
            }
            // Add 1 to include the origin point 'i' itself
            max_pts = max(max_pts, local_max + 1);
        }
        
        return max_pts;
    }
};