#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int word_len = words[0].length();
        int num_words = words.size();
        int total_len = word_len * num_words;
        int s_len = s.length();

        if (s_len < total_len) return result;

        // Build word frequency map
        unordered_map<string, int> word_count;
        for (const string& word : words) {
            word_count[word]++;
        }

        // Run sliding window for each offset from 0 to word_len - 1
        for (int i = 0; i < word_len; ++i) {
            int left = i, right = i;
            unordered_map<string, int> seen;
            int count = 0;

            while (right + word_len <= s_len) {
                string sub = s.substr(right, word_len);
                right += word_len;

                if (word_count.count(sub)) {
                    seen[sub]++;
                    count++;

                    // If word frequency exceeds expected, advance left pointer
                    while (seen[sub] > word_count[sub]) {
                        string left_word = s.substr(left, word_len);
                        seen[left_word]--;
                        count--;
                        left += word_len;
                    }

                    // Found a valid substring
                    if (count == num_words) {
                        result.push_back(left);
                    }
                } else {
                    // Invalid word found: reset the window
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};