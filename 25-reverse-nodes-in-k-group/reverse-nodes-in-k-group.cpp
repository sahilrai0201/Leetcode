class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        //check if size is >= k
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL && len < k){
            temp = temp->next;
            len++;
        }

        //base case
        if(len < k){
            return head;
        }

        //step1: reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        int count = 0;

        while(curr != NULL && count < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        //setp2: recursive part
        if(forward != NULL){
            head->next = reverseKGroup(forward, k);
        }

        //step3: return answer
        return prev;
    }
};