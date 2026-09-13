class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        // Base case: if the node is null, return
        if (root == nullptr) {
            return;
        }
        
        // Traverse the left subtree
        inorder(root->left, result);
        
        // Visit the root (current node)
        result.push_back(root->val);
        
        // Traverse the right subtree
        inorder(root->right, result);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};