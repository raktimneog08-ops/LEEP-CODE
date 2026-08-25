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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* lastSorted = head;
        ListNode* curr = head->next;

        while (curr) {
            if (curr->val >= lastSorted->val) {
                // Already in sorted order, move lastSorted boundary
                lastSorted = lastSorted->next;
            } else {
                // Find the insertion spot starting from dummy
                ListNode* prev = &dummy;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }

                // Remove curr from its current position
                lastSorted->next = curr->next;

                // Insert curr between prev and prev->next
                curr->next = prev->next;
                prev->next = curr;
            }
            // Move to the next node to process
            curr = lastSorted->next;
        }

        return dummy.next;
    }
};