class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //create a dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        //move fast pointer n steps ahead
        for(int i=0; i<n; i++){
            fast = fast->next;
        }

        //move both pointers until fast reaches the last node
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        //delete the nth node from the end
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return dummy->next;
    }
};