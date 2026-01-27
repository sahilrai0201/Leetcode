class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        //edge case
        if(head == NULL || head->next == NULL) return NULL;

        //find middle
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;

        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        //delete middle node
        prev->next = slow->next;

        //return head of the LL
        return head;
    }
};