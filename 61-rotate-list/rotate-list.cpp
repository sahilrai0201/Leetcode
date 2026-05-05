//APPROACH 3 : OPTIMISED SOLUTION ----------------------------------------------->
//TC = O(N) & SC = O(1) --------------------------------------------------------->
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        //Step 1 : Find length and last node
        ListNode* temp = head;
        int n = 1;

        while(temp->next != NULL){
            temp = temp->next;
            n++;
        }

        //Step 2 : Reduce k
        k = k % n;
        if(k == 0) return head;   //no rotation needed

        //Step 3 : Make Circular
        temp->next = head;

        //Step 4 : Find new tail (n-k steps)
        int steps = n-k;
        ListNode* newTail = head;

        for(int i=1; i<steps; i++){
            newTail = newTail->next;
        }

        //Step 5 : Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};




//APPROACH 2 : BETTER SOLUTION ----------------------------------------------------->
//TC = O(N*N) & SC = O(1) ---------------------------------------------------------->
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(!head || !head->next || k == 0) return head;

//         //Step 1 : Find length
//         int n = 0;
//         ListNode* temp = head;
//         while(temp != NULL){
//             n++;
//             temp = temp->next;
//         }

//         //Step 2 : Reduce k
//         k = k % n;
//         if(k == 0) return head;

//         //Step 3 : Same brute force logic
//         for(int i=0; i<k; i++){
//             ListNode* temp = head;
//             ListNode* prev = NULL;

//             while(temp->next != NULL){
//                 prev = temp;
//                 temp = temp->next;
//             }

//             prev->next = NULL;
//             temp->next = head;
//             head = temp;
//         }

//         return head;
//     }
// };





//APPROACH 1 : BRUTE FORCE ----------------------------------------------------->
//TC = O(K*N) & SC = O(1) ------------------------------------------------------>
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