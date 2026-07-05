// APPROACH_1: TC = O(N) & SC = O(N) :
class Solution {
public:
    bool checkPalindrome(vector<int> arr){
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s <= e){
            if(arr[s] != arr[e]) return false;
            s++;
            e--;
        }
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        return checkPalindrome(arr);
    }
};

// APPROACH_2 : TC = O(N) & SC = O(1) :
// class Solution {
// public:
//     //function to reverse the list
//     ListNode* reverseList(ListNode* head){
//         ListNode* prev = NULL;
//         ListNode* curr = head;

//         while(curr != NULL){
//             ListNode* forward = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = forward;
//         }
//         return prev;
//     }

//     bool isPalindrome(ListNode* head) {
//         if(head == NULL || head->next == NULL) return true;

//         //step1: find middle using slow & fast pointers
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while(fast->next != NULL && fast->next->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         //step2: reverse second half
//         slow->next = reverseList(slow->next);
//         ListNode* secondHead = slow->next;

//         //compare both halves
//         ListNode* firstHead = head;
//         while(secondHead != NULL){
//             if(firstHead->val != secondHead->val) return false;

//             firstHead = firstHead->next;
//             secondHead = secondHead->next;
//         }
//         return true;
//     }
// };