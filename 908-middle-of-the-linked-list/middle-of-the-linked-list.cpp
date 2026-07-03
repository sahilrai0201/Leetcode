// TC = O(N) & SC = O(1) : 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Initialize two pointers:
        // slow moves one step at a time.
        // fast moves two steps at a time.
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse until fast reaches the end of the list.
        while (fast != NULL && fast->next != NULL) {

            // Move slow by one node.
            slow = slow->next;

            // Move fast by two nodes.
            fast = fast->next->next;
        }

        // When the loop ends:
        // - If the list has an odd number of nodes,
        //   slow points to the middle node.
        // - If the list has an even number of nodes,
        //   slow points to the second middle node.
        return slow;
    }
};