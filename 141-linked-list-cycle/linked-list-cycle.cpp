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