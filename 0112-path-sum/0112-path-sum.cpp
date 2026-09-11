class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: if the tree/subtree is empty
        if (root == nullptr) {
            return false;
        }
        
        // If it is a leaf node, check if its value equals the remaining sum
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        
        // Recursively check the left and right subtrees with the updated target sum
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};