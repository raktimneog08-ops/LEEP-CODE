class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            // Update the lowest price seen so far
            if (price < minPrice) {
                minPrice = price;
            } 
            // Calculate profit if we sell today and update maxProfit if it's the highest
            else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }
        
        return maxProfit;
    }
};
