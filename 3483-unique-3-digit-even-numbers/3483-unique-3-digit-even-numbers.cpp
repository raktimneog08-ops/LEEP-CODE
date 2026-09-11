class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Step 1: Count the frequency of each digit in the input
        vector<int> availableCount(10, 0);
        for (int digit : digits) {
            availableCount[digit]++;
        }
        
        int ans = 0;
        
        // Step 2: Iterate through all possible 3-digit even numbers
        for (int num = 100; num < 1000; num += 2) {
            vector<int> currentCount(10, 0);
            int temp = num;
            
            // Extract the digits of the current number
            while (temp > 0) {
                currentCount[temp % 10]++;
                temp /= 10;
            }
            
            // Step 3: Check if we have enough digits to form 'num'
            bool canForm = true;
            for (int i = 0; i < 10; i++) {
                if (currentCount[i] > availableCount[i]) {
                    canForm = false;
                    break;
                }
            }
            
            // Step 4: If valid, increment the count
            if (canForm) {
                ans++;
            }
        }
        
        return ans;
    }
};