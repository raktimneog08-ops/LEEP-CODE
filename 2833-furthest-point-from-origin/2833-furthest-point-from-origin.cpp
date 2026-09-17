class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int distance = 0;
        int underscores = 0;
        
        for (char c : moves) {
            if (c == 'L') {
                distance--;
            } else if (c == 'R') {
                distance++;
            } else {
                underscores++;
            }
        }
        
        // The maximum distance is the absolute net distance from L and R,
        // plus all the underscore moves in that same direction.
        return abs(distance) + underscores;
    }
};