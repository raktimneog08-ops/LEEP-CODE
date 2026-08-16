#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> current_line_words;
        int current_len = 0;

        for (const string& word : words) {
            // Check if adding the new word (and its minimum 1 space) exceeds maxWidth
            if (current_line_words.size() + current_len + word.length() > maxWidth) {
                
                int spaces_to_distribute = maxWidth - current_len;
                string line = "";
                
                // Case 1: Only one word on the line, it must be left-justified
                if (current_line_words.size() == 1) {
                    line = current_line_words[0] + string(spaces_to_distribute, ' ');
                } 
                // Case 2: Multiple words, distribute spaces evenly
                else {
                    int base_spaces = spaces_to_distribute / (current_line_words.size() - 1);
                    int extra_spaces = spaces_to_distribute % (current_line_words.size() - 1);
                    
                    for (int i = 0; i < current_line_words.size(); ++i) {
                        line += current_line_words[i];
                        // Don't add spaces after the last word in the line
                        if (i < current_line_words.size() - 1) {
                            int spaces_to_add = base_spaces + (i < extra_spaces ? 1 : 0);
                            line += string(spaces_to_add, ' ');
                        }
                    }
                }
                
                result.push_back(line);
                current_line_words.clear();
                current_len = 0;
            }
            
            // Add the current word to the line
            current_line_words.push_back(word);
            current_len += word.length();
        }
        
        // Handle the last line (Case 3): Must be left-justified and words separated by a single space
        string last_line = "";
        for (int i = 0; i < current_line_words.size(); ++i) {
            last_line += current_line_words[i];
            if (i < current_line_words.size() - 1) {
                last_line += " ";
            }
        }
        
        // Pad the remaining characters on the right with spaces
        last_line += string(maxWidth - last_line.length(), ' ');
        result.push_back(last_line);
        
        return result;
    }
};