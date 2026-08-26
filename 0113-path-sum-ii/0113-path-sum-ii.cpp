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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        dfs(root, targetSum, currentPath, allPaths);
        return allPaths;
    }

private:
    void dfs(TreeNode* node, int remainingSum, vector<int>& currentPath, vector<vector<int>>& allPaths) {
        if (!node) return;

        // Add current node to the path
        currentPath.push_back(node->val);
        remainingSum -= node->val;

        // Check if it's a leaf node with the matching sum
        if (!node->left && !node->right && remainingSum == 0) {
            allPaths.push_back(currentPath);
        } else {
            dfs(node->left, remainingSum, currentPath, allPaths);
            dfs(node->right, remainingSum, currentPath, allPaths);
        }

        // Backtrack
        currentPath.pop_back();
    }
};