#include <vector>

using namespace std;

// Segment Tree Node to hold the prefix product states
struct Node {
    int total_prod;
    int count[5]; // Fixed size 5 since constraint says k <= 5
    
    Node() {
        total_prod = 1; // Multiplicative identity
        for (int i = 0; i < 5; ++i) {
            count[i] = 0;
        }
    }
};

class SegmentTree {
    vector<Node> tree;
    int n;
    int k;

    // Helper to merge two child nodes into a parent node
    Node merge(const Node& left, const Node& right) {
        Node res;
        // Total product is the product of both segments modulo k
        res.total_prod = (left.total_prod * right.total_prod) % k;
        
        // 1. Inherit prefix counts directly from the left child
        for (int i = 0; i < k; ++i) {
            res.count[i] = left.count[i];
        }
        
        // 2. Add prefixes from the right child, offset by the left child's total product
        for (int i = 0; i < k; ++i) {
            if (right.count[i] > 0) {
                res.count[(left.total_prod * i) % k] += right.count[i];
            }
        }
        
        return res;
    }

    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            int val = nums[start] % k;
            tree[node].total_prod = val;
            tree[node].count[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node + 1, start, mid, nums);
        build(2 * node + 2, mid + 1, end, nums);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int v = val % k;
            tree[node].total_prod = v;
            for (int i = 0; i < k; ++i) tree[node].count[i] = 0;
            tree[node].count[v] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    Node query(int node, int start, int end, int l, int r) {
        // Out of bounds: return multiplicative identity node
        if (r < start || end < l) {
            return Node(); 
        }
        // Completely within bounds
        if (l <= start && end <= r) {
            return tree[node];
        }
        // Partial overlap
        int mid = start + (end - start) / 2;
        Node left = query(2 * node + 1, start, mid, l, r);
        Node right = query(2 * node + 2, mid + 1, end, l, r);
        return merge(left, right);
    }

public:
    SegmentTree(const vector<int>& nums, int mod_k) {
        n = nums.size();
        k = mod_k;
        tree.resize(4 * n);
        build(0, 0, n - 1, nums);
    }

    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }

    int query(int l, int r, int x) {
        if (l > r) return 0;
        Node res = query(0, 0, n - 1, l, r);
        return res.count[x];
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        // Initialize Segment Tree with the starting array
        SegmentTree st(nums, k);
        vector<int> result;
        result.reserve(queries.size());
        
        for (const auto& q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            
            // 1. Point update: update nums[index_i] to value_i
            st.update(index, value);
            
            // 2. Range Query: get the number of valid prefixes in nums[start_i...n-1]
            result.push_back(st.query(start, nums.size() - 1, x));
        }
        
        return result;
    }
};