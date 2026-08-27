#include <string>

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        int n = version1.length();
        int m = version2.length();
        int i = 0, j = 0;

        while (i < n || j < m) {
            long long num1 = 0;
            while (i < n && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            long long num2 = 0;
            while (j < m && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;

            // Move past the dot delimiter
            if (i < n) i++;
            if (j < m) j++;
        }

        return 0;
    }
};