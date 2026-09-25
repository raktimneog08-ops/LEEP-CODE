#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> braceExpansionII(std::string expression) {
        int index = 0;
        std::unordered_set<std::string> resultSet = parseExpr(expression, index);
        
        // Return sorted lexicographical order as required
        std::vector<std::string> result(resultSet.begin(), resultSet.end());
        std::sort(result.begin(), result.end());
        return result;
    }

private:
    // Expr -> Term (',' Term)*
    std::unordered_set<std::string> parseExpr(const std::string& s, int& idx) {
        std::unordered_set<std::string> result = parseTerm(s, idx);

        while (idx < s.length() && s[idx] == ',') {
            idx++; // Consume ','
            std::unordered_set<std::string> nextTerm = parseTerm(s, idx);
            // Union: result = result U nextTerm
            result.insert(nextTerm.begin(), nextTerm.end());
        }

        return result;
    }

    // Term -> Factor+ (Cartesian product / Concatenation)
    std::unordered_set<std::string> parseTerm(const std::string& s, int& idx) {
        // Multiplicative identity: {""}
        std::unordered_set<std::string> current = {""};

        // A factor starts with either a lowercase letter or '{'
        while (idx < s.length() && (std::isalpha(s[idx]) || s[idx] == '{')) {
            std::unordered_set<std::string> nextFactor = parseFactor(s, idx);
            
            // Cartesian product of current and nextFactor
            std::unordered_set<std::string> concatenated;
            for (const std::string& prefix : current) {
                for (const std::string& suffix : nextFactor) {
                    concatenated.insert(prefix + suffix);
                }
            }
            current = std::move(concatenated);
        }

        return current;
    }

    // Factor -> [a-z]+ | '{' Expr '}'
    std::unordered_set<std::string> parseFactor(const std::string& s, int& idx) {
        if (s[idx] == '{') {
            idx++; // Consume '{'
            std::unordered_set<std::string> inner = parseExpr(s, idx);
            idx++; // Consume '}'
            return inner;
        }

        // Parse consecutive lowercase letters
        std::string literal = "";
        while (idx < s.length() && std::isalpha(s[idx])) {
            literal += s[idx];
            idx++;
        }
        return {literal};
    }
};