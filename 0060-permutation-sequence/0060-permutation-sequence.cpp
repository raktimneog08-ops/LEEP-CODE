#include <string>
#include <vector>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::vector<int> numbers;
        std::vector<int> factorial(n, 1);
        std::string result = "";
        
        // Precompute factorials: factorial[i] will store i!
        // We only need up to (n-1)!
        int fact = 1;
        for (int i = 1; i < n; i++) {
            fact *= i;
            factorial[i] = fact;
        }
        
        // Populate the available numbers [1, 2, ..., n]
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }
        
        // Convert k to 0-indexed to make the math easier
        k = k - 1;
        
        // Determine the number for each of the n positions
        for (int i = n; i > 0; i--) {
            // Find the index of the number to place at the current position
            int index = k / factorial[i - 1];
            
            // Append the number to the result
            result += std::to_string(numbers[index]);
            
            // Remove the used number from our available options
            numbers.erase(numbers.begin() + index);
            
            // Update k for the next iteration
            k = k % factorial[i - 1];
        }
        
        return result;
    }
};