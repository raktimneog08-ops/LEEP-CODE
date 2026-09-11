class Solution {
public:
    int minDepth(TreeNode* root) {
        // Base case: empty tree
        if (root == nullptr) {
            return 0;
        }
        
        // If it's a leaf node (no children)
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        
        // If left subtree is NULL, minimum depth must be in the right subtree
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }
        
        // If right subtree is NULL, minimum depth must be in the left subtree
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }
        
        // If both subtrees exist, find the minimum of both and add 1 for the current node
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};