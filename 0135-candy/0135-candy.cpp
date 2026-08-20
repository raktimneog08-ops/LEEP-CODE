class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // Give every child 1 candy initially to satisfy the first condition
        vector<int> candies(n, 1);
        
        // First pass: Left to Right
        // Ensure children with a higher rating than their left neighbor get more candies
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        // Second pass: Right to Left
        // Ensure children with a higher rating than their right neighbor get more candies
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                // Use max to keep the condition established in the first pass valid
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        // Sum up all the candies
        int totalCandies = 0;
        for (int c : candies) {
            totalCandies += c;
        }
        
        return totalCandies;
    }
};