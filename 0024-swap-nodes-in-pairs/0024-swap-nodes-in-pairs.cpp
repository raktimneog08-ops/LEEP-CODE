class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node acts as a prev node for the head of the list
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            // Identify the two nodes to swap
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Perform the swap
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev two nodes ahead for the next pair
            prev = first;
        }

        return dummy.next;
    }
};