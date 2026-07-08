class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // If any list is empty, no intersection.
        if (!headA || !headB) return NULL;

        // Start pointers from both heads.
        ListNode* a = headA;
        ListNode* b = headB;

        // Keep moving until both pointers meet.
        while (a != b) {

            // Move to next node, or switch to other list.
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        // Return intersection node or NULL.
        return a;
    }
};