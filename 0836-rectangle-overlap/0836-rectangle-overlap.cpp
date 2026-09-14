class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Check if either rectangle is actually a line or a point (area = 0)
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3] ||
            rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
            return false;
        }

        // If not overlapping, one must be strictly to the side of the other
        return !(rec1[2] <= rec2[0] ||   // rec1 is to the left of rec2
                 rec1[3] <= rec2[1] ||   // rec1 is below rec2
                 rec1[0] >= rec2[2] ||   // rec1 is to the right of rec2
                 rec1[1] >= rec2[3]);    // rec1 is above rec2
    }
};