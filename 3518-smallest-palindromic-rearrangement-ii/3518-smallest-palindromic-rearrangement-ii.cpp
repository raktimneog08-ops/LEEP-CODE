#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Using global variables to cache combinations across multiple test cases.
const int MAX_K = 1000005;
vector<vector<int>> C;
bool initialized = false;

void buildCombinations() {
    if (initialized) return;
    // Max half-length is 5000 (since max string length is 10000).
    C.assign(5005, vector<int>(5005, 0));
    for (int i = 0; i <= 5000; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            // Cap to avoid integer overflow, as we only care if permutations >= k
            if (C[i][j] > MAX_K) {
                C[i][j] = MAX_K;
            }
        }
    }
    initialized = true;
}

class Solution {
public:
    // Calculates the total unique permutations for a given character count multiset
    long long calc_perms(const vector<int>& counts) {
        int len = 0;
        for (int x : counts) {
            len += x;
        }
        long long perms = 1;
        for (int x : counts) {
            if (x > 0) {
                perms *= C[len][x];
                if (perms > MAX_K) perms = MAX_K;
                len -= x;
            }
        }
        return perms;
    }

    string smallestPalindrome(string s, int k) {
        buildCombinations();
        
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        string mid = "";
        vector<int> half(26, 0);
        int len = 0;
        
        // Prepare counts for the first half and find the middle character
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                mid += (char)('a' + i);
            }
            half[i] = freq[i] / 2;
            len += half[i];
        }
        
        // Total possible valid palindromic rearrangements
        long long total_perms = calc_perms(half);
        if (total_perms < k) {
            return ""; // k exceeds available permutations
        }
        
        string res_half = "";
        
        // Build the first half greedily
        for (int i = 0; i < len; i++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] > 0) {
                    half[c]--; // Temporarily place character 'c'
                    
                    long long P = calc_perms(half);
                    
                    if (P >= k) {
                        res_half += (char)('a' + c);
                        break; // Character c is fixed, move to next position
                    } else {
                        // The answer doesn't start with 'c', subtract possibilities and try next
                        k -= P;
                        half[c]++; // Revert count
                    }
                }
            }
        }
        
        // Construct the full palindrome
        string res = res_half + mid;
        reverse(res_half.begin(), res_half.end());
        res += res_half;
        
        return res;
    }
};