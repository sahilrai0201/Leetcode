//BETTER SOLUTION ----------------------------------------------------->
//TC = O(K*N) & SC = O(1) -------------------------------------------------->
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        //Step 1 : Find length
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }

        //Step 2 : Reduce k
        k = k % n;
        if(k == 0) return head;

        //Step 3 : Same brute force logic
        for(int i=0; i<k; i++){
            ListNode* temp = head;
            ListNode* prev = NULL;

            while(temp->next != NULL){
                prev = temp;
                temp = temp->next;
            }

            prev->next = NULL;
            temp->next = head;
            head = temp;
        }

        return head;
    }
};




//BRUTE FORCE ----------------------------------------------------->
//TC = O(K*N) & SC = O(1) -------------------------------------------------->
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(!head || !head->next || k == 0) return head;

//         for(int i=0; i<k; i++){
//             // Step 1: go to last node and keep track of second last
//             ListNode* temp = head;
//             ListNode* prev = NULL;

//             while(temp->next != NULL){
//                 prev = temp;
//                 temp = temp->next;
//             }

//             //temp = last node
//             //prev = second last node

//             // Step 2: move last node to front
//             prev->next = NULL;
//             temp->next = head;
//             head = temp;
//         }

//         return head;
//     }
// };