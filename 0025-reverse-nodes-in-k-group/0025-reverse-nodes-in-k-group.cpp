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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *groupPrev = &dummy;

        while (true) {
            // Check if there are at least k nodes remaining
            ListNode *kth = getKthNode(groupPrev, k);
            if (!kth) break;

            ListNode *groupNext = kth->next;
            
            // Reverse current k-group
            ListNode *prev = groupNext;
            ListNode *curr = groupPrev->next;
            while (curr != groupNext) {
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Update connections for the next iteration
            ListNode *temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy.next;
    }

private:
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};