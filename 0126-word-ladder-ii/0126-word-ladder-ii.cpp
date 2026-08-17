#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        
        // If the target word is not in the dictionary, no sequence exists.
        if (dict.find(endWord) == dict.end()) return ans;
        
        // Maps a word to its predecessors (parents) to easily backtrack later.
        unordered_map<string, vector<string>> adj; 
        unordered_set<string> currentLayer;
        currentLayer.insert(beginWord);
        
        bool found = false;
        
        // Step 1: BFS to find the shortest paths and build the adjacency list
        while (!currentLayer.empty() && !found) {
            // Remove all words of the current layer from the dictionary
            // so we don't visit them again in deeper layers or create cycles.
            for (const string& word : currentLayer) {
                dict.erase(word);
            }
            
            unordered_set<string> nextLayer;
            
            for (string word : currentLayer) {
                string original = word;
                for (int i = 0; i < word.length(); ++i) {
                    char oldChar = word[i];
                    // Try changing one character at a time
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (word[i] == c) continue;
                        word[i] = c;
                        
                        if (dict.find(word) != dict.end()) {
                            nextLayer.insert(word);
                            adj[word].push_back(original);
                            if (word == endWord) {
                                found = true;
                            }
                        }
                    }
                    word[i] = oldChar; // Restore the original character
                }
            }
            currentLayer = nextLayer;
        }
        
        // Step 2: DFS to backtrack and construct the actual sequences
        if (found) {
            vector<string> path = {endWord};
            dfs(endWord, beginWord, adj, path, ans);
        }
        
        return ans;
    }
    
private:
    void dfs(string& currentWord, string& beginWord, unordered_map<string, vector<string>>& adj, vector<string>& path, vector<vector<string>>& ans) {
        if (currentWord == beginWord) {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end()); // Reverse since we built it backward
            ans.push_back(validPath);
            return;
        }
        
        for (string& parent : adj[currentWord]) {
            path.push_back(parent);
            dfs(parent, beginWord, adj, path, ans);
            path.pop_back(); // Backtrack
        }
    }
};