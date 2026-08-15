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
    ListNode* rotateRight(ListNode* head, int k) {
        // Base cases: empty list, single node, or no rotation needed
        if (!head || !head->next || k == 0) {
            return head;
        }

        // 1. Find the length of the list and locate the tail node
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // 2. Connect the tail to the head to form a circular list
        tail->next = head;

        // 3. Calculate the effective number of rotations
        k = k % length;
        int stepsToNewTail = length - k;

        // 4. Traverse to find the new tail of the list
        ListNode* newTail = tail; 
        while (stepsToNewTail > 0) {
            newTail = newTail->next;
            stepsToNewTail--;
        }

        // 5. Set the new head and break the circular connection
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};