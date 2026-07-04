// TC = O(N) & SC = O(1) : 

class Solution {
private:
    // Helper function to detect whether a cycle exists.
    // If a cycle is found, it returns the meeting point of
    // the slow and fast pointers. Otherwise, it returns NULL.
    ListNode* flyodDetectLoop(ListNode* head) {

        // Empty list -> no cycle.
        if(head == NULL)
            return NULL;

        // Initialize slow and fast pointers.
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the linked list.
        while(fast != NULL && fast->next != NULL){

            // Move slow pointer by one step.
            slow = slow->next;

            // Move fast pointer by two steps.
            fast = fast->next->next;

            // If both pointers meet, a cycle exists.
            if(slow == fast){
                return slow;
            }
        }

        // Fast reached the end, so no cycle exists.
        return NULL;
    }

public:
    ListNode *detectCycle(ListNode *head) {

        // Empty list -> no cycle.
        if(head == NULL)
            return NULL;

        // Find the intersection point inside the cycle.
        ListNode* intersection = flyodDetectLoop(head);

        // No cycle found.
        if(intersection == NULL)
            return NULL;

        // Start one pointer from the head and the other
        // from the intersection point.
        ListNode* slow = head;

        // Move both pointers one step at a time.
        // They will meet at the starting node of the cycle.
        while(slow != intersection){
            slow = slow->next;
            intersection = intersection->next;
        }

        // Return the first node of the cycle.
        return slow;
    }
};