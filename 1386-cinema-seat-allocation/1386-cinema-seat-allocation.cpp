#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Map to store row numbers and a bitmask of reserved seats for that row
        unordered_map<int, int> row_seats;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            
            // We only care about seats 2 through 9. 
            // Shift them to a 0-indexed bitmask (Seat 2 becomes bit 0, Seat 9 becomes bit 7).
            if (col >= 2 && col <= 9) {
                row_seats[row] |= (1 << (col - 2)); 
            }
        }
        
        // Start by assuming all rows are completely empty
        int max_families = n * 2;
        
        // Process only the rows that have at least one reserved seat (in columns 2-9)
        for (const auto& [row, mask] : row_seats) {
            // Deduct the 2 families we initially assumed for this row
            max_families -= 2;
            
            // Check availability using bitwise AND against our mask
            // Left block (seats 2-5) corresponds to bits 0, 1, 2, 3 -> binary 00001111 (Decimal 15)
            // Middle block (seats 4-7) corresponds to bits 2, 3, 4, 5 -> binary 00111100 (Decimal 60)
            // Right block (seats 6-9) corresponds to bits 4, 5, 6, 7 -> binary 11110000 (Decimal 240)
            
            bool left_free = (mask & 15) == 0;
            bool right_free = (mask & 240) == 0;
            bool middle_free = (mask & 60) == 0;
            
            // Greedily re-add families based on block availability
            if (left_free && right_free) {
                max_families += 2;
            } else if (left_free || right_free || middle_free) {
                max_families += 1;
            }
        }
        
        return max_families;
    }
};