#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to hold segment tree node data
struct Node {
    int len;
    char pref_char;
    int pref_len;
    char suff_char;
    int suff_len;
    int max_len;
};

class Solution {
    vector<Node> tree;
    string str;

    // Helper to merge two segment tree nodes
    Node merge(const Node& left, const Node& right) {
        Node res;
        res.len = left.len + right.len;
        
        // Calculate prefix properties
        res.pref_char = left.pref_char;
        res.pref_len = left.pref_len;
        // If the left child is entirely one character and matches the right's prefix
        if (left.pref_len == left.len && left.pref_char == right.pref_char) {
            res.pref_len += right.pref_len;
        }

        // Calculate suffix properties
        res.suff_char = right.suff_char;
        res.suff_len = right.suff_len;
        // If the right child is entirely one character and matches the left's suffix
        if (right.suff_len == right.len && right.suff_char == left.suff_char) {
            res.suff_len += left.suff_len;
        }

        // The max length is at least the max of the children
        res.max_len = max(left.max_len, right.max_len);
        
        // Check if a sequence crosses the boundary between left and right children
        if (left.suff_char == right.pref_char) {
            res.max_len = max(res.max_len, left.suff_len + right.pref_len);
        }

        return res;
    }

    // Build the segment tree initially
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, str[start], 1, str[start], 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    // Update a single character at `idx` and recalculate up the tree
    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = {1, val, 1, val, 1, 1};
            str[idx] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (start <= idx && idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        str = s;
        // The maximum size of a segment tree array is roughly 4*N
        tree.resize(4 * n); 
        
        // Build the initial tree for the starting string
        build(1, 0, n - 1);
        
        int k = queryCharacters.length();
        vector<int> ans;
        ans.reserve(k);
        
        // Process each query
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            // The root node (1) always holds the max_len for the entire string (0 to n-1)
            ans.push_back(tree[1].max_len);
        }
        
        return ans;
    }
};