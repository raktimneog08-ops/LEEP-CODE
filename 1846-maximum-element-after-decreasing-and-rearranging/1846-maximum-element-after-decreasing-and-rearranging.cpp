#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        // Step 2: The first element must be 1
        arr[0] = 1;
        
        // Step 3: Iterate and constrain each element based on the previous one
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }
        
        // Step 4: The last element is guaranteed to be the maximum
        return arr.back();
    }
};