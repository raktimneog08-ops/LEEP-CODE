class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        
        for (size_t i = 1; i < prices.size(); ++i) {
            // Greedily capture every positive price increase
            if (prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];
            }
        }
        
        return max_profit;
    }
};