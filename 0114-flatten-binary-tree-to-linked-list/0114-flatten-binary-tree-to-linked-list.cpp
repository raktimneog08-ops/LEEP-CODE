class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Find the rightmost node in the left subtree
                TreeNode* prev = curr->left;
                while (prev->right != nullptr) {
                    prev = prev->right;
                }
                
                // Connect the original right subtree to the rightmost node of left subtree
                prev->right = curr->right;
                
                // Move the left subtree to the right
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // Move to the next right node
            curr = curr->right;
        }
    }
};