class Solution {
public:
    string multiply(string num1, string num2) {
        // If either string is 0, the product is 0
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        int n = num1.length();
        int m = num2.length();
        
        // The maximum length of the product is n + m
        vector<int> res(n + m, 0);
        
        // Multiply each digit from right to left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                
                // Add the product to the current position in our result array
                int sum = mul + res[i + j + 1];
                
                // Update the current position with the single digit
                res[i + j + 1] = sum % 10;
                
                // Add the carry to the next position
                res[i + j] += sum / 10;
            }
        }
        
        // Convert the result array to a string, skipping leading zeros
        string result = "";
        for (int val : res) {
            if (!(result.empty() && val == 0)) {
                result.push_back(val + '0');
            }
        }
        
        return result.empty() ? "0" : result;
    }
};