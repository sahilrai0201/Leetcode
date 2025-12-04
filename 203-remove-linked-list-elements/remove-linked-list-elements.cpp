class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //empty list
        if(head == NULL) return head;      

        //create dummy for the deletion at head position
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr != NULL){
            if(curr->val == val){
                prev->next = curr->next;     //unlink node
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;
            }
            else{        //no deletion
                prev = curr;
                curr = curr->next;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};