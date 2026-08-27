class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        // Custom comparator: sort in descending order based on combined string value
        sort(strNums.begin(), strNums.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        // Edge case: if the largest number is "0", the whole number is 0
        if (strNums[0] == "0") {
            return "0";
        }

        string result = "";
        for (const string& s : strNums) {
            result += s;
        }

        return result;
    }
};