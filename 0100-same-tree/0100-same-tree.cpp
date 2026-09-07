class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case 1: If both nodes are null, the trees match at this leaf
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // Base case 2: If one node is null but the other isn't, the structures differ
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // Base case 3: If the values at the current nodes differ, they aren't the same
        if (p->val != q->val) {
            return false;
        }
        
        // Recursive step: Both left and right subtrees must match
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};