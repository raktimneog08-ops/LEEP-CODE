#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        // Step 1: Create a copy of the array and sort it
        std::vector<int> sortedArr = arr;
        std::sort(sortedArr.begin(), sortedArr.end());
        
        // Step 2: Assign ranks to unique elements using a hash map
        std::unordered_map<int, int> ranks;
        int rank = 1;
        for (int num : sortedArr) {
            // Only assign a rank if the number hasn't been seen yet
            if (ranks.find(num) == ranks.end()) {
                ranks[num] = rank++;
            }
        }
        
        // Step 3: Map the original array elements to their assigned ranks
        std::vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            result[i] = ranks[arr[i]];
        }
        
        return result;
    }
};