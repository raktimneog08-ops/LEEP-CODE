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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        // Traverse each node and reverse the next pointer
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // Store reference to next node
            curr->next = prev;               // Invert pointer direction
            prev = curr;                     // Move prev forward
            curr = nextTemp;                 // Move curr forward
        }

        // 'prev' is the new head of the reversed list
        return prev;
    }
};