// TC = O(N) & SC = O(1) :

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // If the list is empty or contains only one node,
        // it is already reversed.
        if(head == NULL || head->next == NULL){
            return head;
        }

        // Initialize three pointers:
        // prev    -> Points to the previous node.
        // curr    -> Points to the current node being processed.
        // forward -> Stores the next node before changing the link.
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        // Traverse the entire linked list.
        while(curr != NULL){

            // Store the next node.
            forward = curr->next;

            // Reverse the current node's pointer.
            curr->next = prev;

            // Move prev and curr one step forward.
            prev = curr;
            curr = forward;
        }

        // 'prev' now points to the new head of the reversed list.
        return prev;
    }
};