#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;
        int current_tank = 0;
        int start_station = 0;
        
        for (int i = 0; i < gas.size(); ++i) {
            int net_gain = gas[i] - cost[i];
            total_tank += net_gain;
            current_tank += net_gain;
            
            // If unable to reach the next station, reset the start station
            if (current_tank < 0) {
                start_station = i + 1;
                current_tank = 0;
            }
        }
        
        return total_tank >= 0 ? start_station : -1;
    }
};