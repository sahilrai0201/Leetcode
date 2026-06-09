//TC = O(N) & SC = O(1) ------------------------------------>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Create a dummy node to handle edge cases
        // such as deleting the head node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Initialize both pointers at the dummy node
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers together until fast reaches
        // the last node of the list
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow is now just before the node to be deleted
        ListNode* NodeToDelete = slow->next;

        // Remove the target node from the list
        slow->next = slow->next->next;

        // Free the memory of the deleted node
        delete NodeToDelete;

        // Return the updated head of the list
        return dummy->next;
    }
};
