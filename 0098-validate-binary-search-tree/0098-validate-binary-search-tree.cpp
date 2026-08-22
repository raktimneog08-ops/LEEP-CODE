class Solution {
public:
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        if (!node) return true;
        
        // Node value must strictly lie within (minVal, maxVal)
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }
        
        // Left child must be in (minVal, node->val)
        // Right child must be in (node->val, maxVal)
        return validate(node->left, minVal, node->val) && 
               validate(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};