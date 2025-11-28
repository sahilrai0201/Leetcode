//flyod loop detection approach
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //empty list
        if(head == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        while(slow != NULL && fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            slow = slow->next;
            if(slow == fast){
                //loop detected
                return slow;
            }
        }
        return NULL;
    }
}; 

/*
//hashing approach
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //empty list - No loop possible
        if(head == NULL){
            return false;
        }

        unordered_map<ListNode*, bool> visited;
        ListNode* temp = head;

        while(temp != NULL){
            //cycle is present
            if(visited[temp] == true){
                return true;
            }
            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }
}; 
*/