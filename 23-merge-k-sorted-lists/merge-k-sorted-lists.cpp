class Solution {
public:

    // Custom comparator to make the priority_queue a min-heap
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min-heap storing nodes based on their values
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Put the first node of every non-empty list into the heap
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        // Dummy node to simplify building the result list
        ListNode dummy(0);

        // tail always points to the last node of the merged list
        ListNode* tail = &dummy;

        // Continue until all nodes have been processed
        while (!pq.empty()) {

            // Get the node with the smallest value
            ListNode* curr = pq.top();
            pq.pop();

            // Add the smallest node to the result list
            tail->next = curr;
            tail = curr;

            // If this node has a next node,
            // add it to the heap for future comparison
            if (curr->next != nullptr) {
                pq.push(curr->next);
            }
        }

        // dummy.next is the head of the merged linked list
        return dummy.next;
    }
};