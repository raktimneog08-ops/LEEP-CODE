#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord is not in wordList, no transformation sequence exists
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        // Remove beginWord if it exists in the set to prevent revisiting
        wordSet.erase(beginWord);
        
        while (!q.empty()) {
            auto [currentWord, steps] = q.front();
            q.pop();
            
            if (currentWord == endWord) {
                return steps;
            }
            
            // Try changing each character to 'a'-'z'
            for (int i = 0; i < currentWord.length(); ++i) {
                char originalChar = currentWord[i];
                
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == originalChar) continue;
                    
                    currentWord[i] = c;
                    
                    if (wordSet.count(currentWord)) {
                        q.push({currentWord, steps + 1});
                        wordSet.erase(currentWord); // Mark as visited
                    }
                }
                
                currentWord[i] = originalChar; // Restore character
            }
        }
        
        return 0;
    }
};