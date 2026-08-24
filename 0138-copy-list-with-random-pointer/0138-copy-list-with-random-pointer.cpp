/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Interweave cloned nodes with original nodes
        Node* curr = head;
        while (curr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        // Step 2: Assign random pointers for cloned nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the two interleaved lists
        curr = head;
        Node* cloneHead = head->next;
        Node* cloneCurr = cloneHead;

        while (curr) {
            curr->next = curr->next->next;
            if (cloneCurr->next) {
                cloneCurr->next = cloneCurr->next->next;
            }
            curr = curr->next;
            cloneCurr = cloneCurr->next;
        }

        return cloneHead;
    }
};