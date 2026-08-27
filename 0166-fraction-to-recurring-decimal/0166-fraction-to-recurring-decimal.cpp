#include <string>
#include <unordered_map>
#include <cmath>

class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        std::string result = "";

        // Determine sign
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }

        // Use long long to avoid overflow with INT_MIN
        long long num = std::abs(static_cast<long long>(numerator));
        long long den = std::abs(static_cast<long long>(denominator));

        // Integral part
        result += std::to_string(num / den);
        long long rem = num % den;

        if (rem == 0) return result;

        result += ".";

        // Map remainder to its position in the result string
        std::unordered_map<long long, int> remainderPos;

        while (rem != 0) {
            if (remainderPos.find(rem) != remainderPos.end()) {
                result.insert(remainderPos[rem], "(");
                result += ")";
                break;
            }

            remainderPos[rem] = result.length();
            rem *= 10;
            result += std::to_string(rem / den);
            rem %= den;
        }

        return result;
    }
};