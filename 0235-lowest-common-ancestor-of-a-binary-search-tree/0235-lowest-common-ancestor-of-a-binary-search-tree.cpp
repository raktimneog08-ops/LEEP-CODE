class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (p->val < curr->val && q->val < curr->val) {
                // Both nodes are in the left subtree
                curr = curr->left;
            } else if (p->val > curr->val && q->val > curr->val) {
                // Both nodes are in the right subtree
                curr = curr->right;
            } else {
                // Found split point, or curr equals p or q
                return curr;
            }
        }

        return nullptr;
    }
};