/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<TreeNode*> buildTrees(int start, int end) {
        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode*> allTrees;

        // Iterate through all values to make each the root
        for (int i = start; i <= end; ++i) {
            // Generate all left and right subtrees
            vector<TreeNode*> leftSubtrees = buildTrees(start, i - 1);
            vector<TreeNode*> rightSubtrees = buildTrees(i + 1, end);

            // Connect root with all combinations of left and right subtrees
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i, left, right);
                    allTrees.push_back(root);
                }
            }
        }

        return allTrees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }
};