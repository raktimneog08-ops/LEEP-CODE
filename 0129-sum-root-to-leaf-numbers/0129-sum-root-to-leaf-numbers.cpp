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
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;

        currentSum = currentSum * 10 + node->val;

        // Leaf node check: return the accumulated path number
        if (!node->left && !node->right) {
            return currentSum;
        }

        // Sum up paths from both left and right subtrees
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};