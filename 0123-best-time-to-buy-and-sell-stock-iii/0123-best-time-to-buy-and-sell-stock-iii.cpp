#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        // Initialize states
        int buy1 = INT_MIN; 
        int sell1 = 0;
        int buy2 = INT_MIN;
        int sell2 = 0;
        
        for (int p : prices) {
            // State transitions
            buy1 = max(buy1, -p);               // Maximize profit after 1st buy (minimizing cost)
            sell1 = max(sell1, buy1 + p);       // Maximize profit after 1st sell
            buy2 = max(buy2, sell1 - p);        // Maximize profit after 2nd buy
            sell2 = max(sell2, buy2 + p);       // Maximize profit after 2nd sell
        }
        
        // sell2 will hold the maximum profit from at most 2 transactions
        return sell2;
    }
};