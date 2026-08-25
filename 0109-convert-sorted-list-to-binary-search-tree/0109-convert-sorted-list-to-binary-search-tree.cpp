/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* curr;

    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }

    TreeNode* buildBST(int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;

        // Construct the left subtree
        TreeNode* leftChild = buildBST(left, mid - 1);

        // Process current node
        TreeNode* root = new TreeNode(curr->val);
        root->left = leftChild;
        curr = curr->next;

        // Construct the right subtree
        root->right = buildBST(mid + 1, right);

        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        int length = getLength(head);
        curr = head;
        return buildBST(0, length - 1);
    }
};