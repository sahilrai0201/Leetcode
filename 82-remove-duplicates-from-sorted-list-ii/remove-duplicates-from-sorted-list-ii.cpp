class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        //empty list
        if(head == NULL) return head;

        //dummy node - to handle deletion at head position
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr != NULL){
            bool hasDuplicates = false;
            while(curr->next != NULL && curr->val == curr->next->val){
                hasDuplicates = true;
                ListNode* temp  = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            if(hasDuplicates){
                //remove the current node also
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;

                //link prev to curr
                prev->next =  curr;
            }
            else{
                //No duplicates
                prev = curr;
                curr = curr->next;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};