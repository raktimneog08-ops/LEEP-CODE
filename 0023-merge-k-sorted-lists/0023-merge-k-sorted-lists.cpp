#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Custom comparator for min-heap
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to keep track of the node with the smallest value
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Push the head node of each non-empty linked list into the heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }

        // Dummy node to serve as the starting anchor for the merged list
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Process nodes until the heap is empty
        while (!minHeap.empty()) {
            // Get the smallest node
            ListNode* minNode = minHeap.top();
            minHeap.pop();

            // Append to the merged list
            tail->next = minNode;
            tail = tail->next;

            // If there's a next node in the same list, push it into the heap
            if (minNode->next != nullptr) {
                minHeap.push(minNode->next);
            }
        }

        return dummy.next;
    }
};