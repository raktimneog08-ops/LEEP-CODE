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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        // Continue looping while there are nodes left in either list, or a carry remains
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get the values from the current nodes, or 0 if the list is exhausted
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate the sum and update the carry for the next iteration
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            
            // Create a new node with the single-digit result and advance the pointer
            current->next = new ListNode(sum % 10);
            current = current->next;
            
            // Move to the next nodes in l1 and l2 if they exist
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // Store the actual result and clean up the dummy head
        ListNode* result = dummyHead->next;
        delete dummyHead; 
        
        return result;
    }
};