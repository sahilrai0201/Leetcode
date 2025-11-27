class Solution {
public:
    int getLength(ListNode* head){
        int len = 0;
        while(head !=NULL){
            len++;
            head = head->next;
        }
        return len;
    }    
public:
    ListNode* middleNode(ListNode* head) {
        int len = getLength(head);
        int ans = (len/2);

        ListNode* temp = head;
        int count = 0;
        while(count < ans){
            temp = temp->next;
            count++;
        }
        return temp;
    }
};