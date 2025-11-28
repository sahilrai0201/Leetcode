class Solution {
private:
    ListNode* flyodDetectLoop(ListNode* head){
        if(head == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        while(slow != NULL && fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            slow = slow->next;
            if(slow == fast){  //loop detected
                return slow;
            }
        }
        return NULL;    //no loop detected
    }    
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        
        ListNode* intersection = flyodDetectLoop(head);
        if(intersection == NULL) return NULL;  //no loop

        ListNode* slow = head;
        while(slow != intersection){
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;     //starting point of cycle
    }
};