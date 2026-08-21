#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) {
            return {};
        }

        unordered_set<string> seen;
        unordered_set<string> repeated;

        for (int i = 0; i + 9 < s.length(); ++i) {
            string sub = s.substr(i, 10);
            if (seen.count(sub)) {
                repeated.insert(sub);
            } else {
                seen.insert(sub);
            }
        }

        return vector<string>(repeated.begin(), repeated.end());
    }
};