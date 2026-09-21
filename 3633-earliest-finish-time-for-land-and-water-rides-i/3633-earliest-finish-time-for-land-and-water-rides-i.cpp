class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int min_finish = 1e9; // Initialize to a large value to track the minimum
        
        // Iterate through all possible pairs of land and water rides
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Option 1: Take land ride 'i' first, then water ride 'j'
                int end_land_first = landStartTime[i] + landDuration[i];
                int start_water_second = max(end_land_first, waterStartTime[j]);
                int finish_option1 = start_water_second + waterDuration[j];
                
                // Option 2: Take water ride 'j' first, then land ride 'i'
                int end_water_first = waterStartTime[j] + waterDuration[j];
                int start_land_second = max(end_water_first, landStartTime[i]);
                int finish_option2 = start_land_second + landDuration[i];
                
                // Keep track of the earliest possible finish time across all combinations and orders
                min_finish = min({min_finish, finish_option1, finish_option2});
            }
        }
        
        return min_finish;
    }
};